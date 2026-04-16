#include<iostream>
using namespace std;

int main() {
	int n = 0;
	int cantcifras = 0;
	do {
		cout<<"Ingrese un numero entero positivo (mayor a 3 cifras): ";cin>>n;
	} while (n < 1000);
	
	int t = n;
	while (t>0) {
		cantcifras++;
		t/=10;
	}
	//Ordenamiento
	int ordenado = 0;
	for (int i = 0; i<10; i++) {
		int vecesdigito = 0;
		t = n;
		while (t>0) {
			int c = t%10;
			if (c == i) {
				vecesdigito++;
			}
			t/=10;
		}
		if (i > 0) {
			for (int j = 1; j<=vecesdigito;j++) {
				ordenado*=10;
				ordenado+=i;
			}	
		}
	}
	
	int mediana;
	t = ordenado;
	if (cantcifras%2 == 1) {
		int digitosaeliminar = cantcifras/2;
		
		for (int i = 1; i<=digitosaeliminar;i++) {
			t/=10;	
		}
		mediana = t%10;
	} else {
		int m = cantcifras/2;
		int digitosaeliminar = m - 1;
		
		for (int i = 1; i<=digitosaeliminar;i++) {
			t/=10;
		}
		
		float c1 = t%10;
		t/=10;
		float c2 = t%10;
		float sum = c1 + c2;
		float prom = sum/2;
		// Se añade 0.5 para que funcione el redondeo (EJ: 2.5 + 0.5 = 3 INT => 3 => Redondeado de 2.5 a 3, 2.0 + 0.5 = 2.5 INT => 2 => Redondeado de 2 a 2)
		float naproximar = prom + 0.5;
		mediana = naproximar;
	}
	
	cout<<"La mediana de las cifras es "<<mediana<<endl;
	
	
	return 0;
}
