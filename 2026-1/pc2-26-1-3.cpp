#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main() {
	srand(time(NULL));
	int n;
	cout<<"Ingrese n: ";
	cin>>n;
	
	int x[4*n];
	
	for (int i = 0; i<n; i++) {
		
		int c1 = 1+rand()%9;
		int c2 = rand()%10;
		int c3 = rand()%10;
		int c4 = rand()%10;
		
		int numero = 1000*c1 + 100*c2 + 10*c3 + 1*c4;
		cout<<numero<<" ";
		
		x[4*i + 0] = c1;
		x[4*i + 1] = c2;
		x[4*i + 2] = c3;
		x[4*i + 3] = c4;
	}
	
	for (int i = 0; i<=9; i++) {
		int sum = 0;
		int cantidad = 0;
		int distancia = 0;
		
		for (int j = 0; j<4*n; j++) {
			distancia++;
			if (x[j] == i) {
				cantidad++;
				sum+=distancia;
				distancia = 0;
			}
		}
		
		
		if (cantidad != 0) {
			float promedio = sum*1.0/cantidad;
			cout<<endl;
			cout<<"Para la cifra "<<i<<", el promedio de distancias es "<<promedio;
		}
		
		
		
	}
}