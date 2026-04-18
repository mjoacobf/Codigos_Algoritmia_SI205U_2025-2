#include<iostream>

using namespace std;

int main() {
	int m = 0;
	int n = 0;
	
	do {
		cout<<"n(A): ";cin>>m;
	} while (m<=0);
	
	int a[m];
	
	for (int i = 0; i<m; i++) {
		int e = 0;
		do {
		cout<<"Ingrese el numero "<<i+1<<" del arreglo A: ";cin>>e;
		} while (e<=0);
		
		for (int j = 0; j<i;j++) {
			if (e == a[j]/10) {
				cout<<"No se pueden repetir los valores."<<endl;
				i--;
				break;
			}
		}
		e*=10;
		e+=i+1;
		a[i] = e;
		
	}
	
	do {
		cout<<"n(B): ";cin>>n;
	} while (n<=0);
	
	int b[n];
	
	for (int i = 0; i<n; i++) {
		int e = 0;
		do {
		cout<<"Ingrese el numero "<<i+1<<" del arreglo B: ";cin>>e;
		} while (e<=0);
		
		
		for (int j = 0; j<i;j++) {
			if (e == b[j]/10) {
				cout<<"No se pueden repetir los valores."<<endl;
				i--;
				break;
			}
		}
		
		e*=10;
		e+=i+1;
		b[i] = e;
	}
	int repetidos = 0;
	for (int i = 0; i<m; i++) {
		for (int j = 0; j<n; j++) {
			if (a[i] == b[j]) {
				repetidos++;
			}
		}
	}
	
	int v = m + n -2*repetidos;
	cout<<"La distancia entre A y B es "<<v;
	
	
	
	return 0;
}
