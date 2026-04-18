#include<iostream>

using namespace std;

int totalpedidos(long long int valor) {
	valor/=1000;
	int total = 0;
	while (valor > 0) {
		total+=valor%100;
		valor/=100;
	}
	
	return total;
}


int main() {
	int n = 0;
	float suma = 0;
	do {
		cout<<"Ingrese la cantidad de productos a analizar (al menos 2): ";cin>>n;
	} while (n<2);
	
	long long int productos[n] = {-1};
	
	for (int i = 0; i<n; i++) {
		
		int codigo = 0;
		do {
			cout<<"Ingrese el codigo del producto "<<i+1<<": ";cin>>codigo;	
		} while (codigo < 100 or codigo > 999);
		productos[i] = codigo;
		
		for (int j = 1; j<=4;j++) {
			long long int numeropedidos;
			cout<<"Ingrese el total de pedidos del producto "<<i+1<<" en el mes "<<j<<" (desde 10 a 99, si ingresa un valor fuera del rango se asume que no tuvo ingresos en ese mes): ";cin>>numeropedidos;
			if (numeropedidos < 10 or numeropedidos > 99) numeropedidos = 0;
			suma+=numeropedidos;
			
			numeropedidos*=1000;
			for (int k = 1; k<j; k++) {
				numeropedidos*=100;
			}
			
			productos[i]+=numeropedidos;
		}
		
	}
	
	float promedio = suma/n;
	cout<<"Promedio de totales: "<<promedio<<endl;
	
	for (int i = 0; i<n; i++){
		cout<<productos[i]<<endl;
		if (totalpedidos(productos[i])*1.0 < promedio) {
			productos[i] = -1;
		}
	}
	
	
	cout<<"Producto\tCodigo\tMes 1\tMes 2\tMes 3\tMes 4"<<endl;
	for (int i = 0; i<n;i++) {
		if (productos[i] > 0) {
			cout<<i+1<<"\t\t"<<productos[i]%1000<<"\t";
			productos[i]/=1000;
			cout<<productos[i]%100<<"\t";
			productos[i]/=100;
			cout<<productos[i]%100<<"\t";
			productos[i]/=100;
			cout<<productos[i]%100<<"\t";
			productos[i]/=100;
			cout<<productos[i]%100<<"\t"<<endl;
		}
	}
	
	
	
	
	return 0;
}
/*
3
200
40
40
0
0
150
20
10
20
0
300
20
30
10
20
*/