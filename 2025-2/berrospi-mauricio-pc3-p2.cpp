#include<iostream>

using namespace std;

int binario (int num) {
	int res = 0;
	int cont = 1;
	while (num>0) {
		int c = num%2;
		num-=c;
		num/=2;
		
		res+=c*cont;
		cont*=10;
	}
	return res;
}

int extraer(int num, int c) {
	for (int i = 0; i<c; i++) {
		num/=10;
	}
	
	return num%10;
}

int p(int b, int x) {
	if (x == 1) return b;
	return b*p(b,x-1);
}

//Funciones recursivas principales
void imprimirconj(int x[], int n, int bin, int j, bool inicio) {
	if (j == n) return;
	if (extraer(bin,n-j-1) == 1) {
				if (not inicio) {
					inicio = true;
					cout<<x[j];
	
				} else {
					
					cout<<", ";
					cout<<x[j];
				}
	}
	imprimirconj(x,n,bin,j+1,inicio);
	return;
}

void subconj(int x[], int n, int i) {
	if (i == p(2, n)) {
		return;
	}
	cout<<"{";
	int bin = binario(i);
	int j = 0;
	bool inicio = false;
	imprimirconj(x,n,bin,j,inicio);
	cout<<"} ";
	subconj(x,n,i+1);
}

int main() {
	int n = 0;
	do {
		cout<<"Ingrese la cantidad de elementos del conjunto (n<5): ";cin>>n;
	} while (n<=0 or n>=5);
	
	int x[n];
	
	for (int i = 0; i<n; i++) {
		cout<<"x["<<i<<"]: ";cin>>x[i];
	}
	cout<<"Subconjuntos: "<<endl;
	int i = 0;
	subconj(x,n,i);
}