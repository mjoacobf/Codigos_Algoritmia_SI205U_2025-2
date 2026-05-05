#include<iostream>

using namespace std;

int main() {
	int m;
	int n;
	cout<<"Cantidad de elementos de A: ";cin>>m;
	cout<<"Cantidad de elementos de B: ";cin>>n;
	
	int a[m];
	int b[n];
	
	int maximo = 0;
	
	for (int i = 0; i<m; i++) {
		cout<<"A["<<i<<"]: ";cin>>a[i];
		if (a[i]>maximo) maximo = a[i];
	}
	
	for (int i = 0; i<n; i++) {
		cout<<"B["<<i<<"]: ";cin>>b[i];
		if (b[i]>maximo) maximo = b[i];
	}
	
	maximo++; //para que el indice cuadre con el numero
	
	int valores[maximo] = {0};
	
	//conteo de valores
	for (int i = 0; i<m; i++) {
		valores[a[i]]++;
	}
	
	for (int i = 0; i<n; i++) {
		valores[b[i]]++;
	}
	
	//creacion de c
	int c[maximo];
	
	int indiceC = 0;
	//agregacion descendiente
	for (int i = maximo-1; i>=0; i--){
		if (valores[i]!=0) {
			c[indiceC] = i;
			indiceC++;
		}
	}
	
	for (int i = 0; i<indiceC; i++) {
		cout<<c[i]<<" ";
	}
}

/*
6
8
6
12
8
16
21
11
9
16
14
27
8
18
24
13
*/