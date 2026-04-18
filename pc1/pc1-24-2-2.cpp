#include<iostream>

using namespace std;

int main() {
	int n;
	cout<<"Ingrese el numero de datos a analizar: ";cin>>n;
	
	float mayor1 = 0;
	float mayor2 = 0;
	int cantMayor1 = 1;
	int cantMayor2 = 1;
	
	bool valor1Ingresado = false;
	bool valor2Ingresado = false;
	
	for (int i = 1; i<=n; i++) {
		float entrada;
		cout<<"Ingrese el numero "<<i<<": ";cin>>entrada;
		
		if (entrada < 0) {
			if (valor1Ingresado == false) {
				mayor1 = entrada;
				valor1Ingresado = true;
			} else if (valor2Ingresado == false) {
				if (entrada == mayor1) {
					cantMayor1++;
				} else {
					mayor2 = entrada;
					valor2Ingresado = true;
					if (mayor1 <mayor2) {
						int t = mayor2;
						mayor2= mayor1;
						mayor1 = t;
					}
				}
			} else {
			if (entrada == mayor2) {
				cantMayor2++;
			} else if (entrada>mayor2) {
				if (entrada == mayor1) {
					cantMayor1++;
				} else {
					if (entrada < mayor1) {
						mayor2 = entrada;
						cantMayor2 = 1;
					} else {
						mayor2 = mayor1;
						cantMayor2 = cantMayor1;
						
						mayor1 = entrada;
						cantMayor1 = 1;
					}
				}
			}
		}
		}
	}
	
	cout<<"Segundo mayor de los negativos: "<<mayor2<<endl;
	cout<<"Apariciones: "<<cantMayor2;
	
	return 0;
}

/*
10
3.1
-4.3
1.1
-8
2.1
-4.3
6
-3
3
1
-3
3

*/