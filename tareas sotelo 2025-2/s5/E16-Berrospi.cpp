#include<iostream>

using namespace std;

int main() {
	int n = 0;
	int maxocurr = 0;
	int max;
	int repetidos = 1;
	
	do {
		cout<<"Ingrese la cantidad de numeros: ";cin>>n;
	} while (n<=0);
	
	int x[n];
	
	for (int i = 0; i<n; i++) {
		cout<<"Ingrese el numero "<<i+1<<": ";cin>>x[i];
	}
	
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n-i; j++) {
			if (x[j] > x[i]) {
				int t = x[j];
				x[j] = x[i];
				x[i] = t;
			}
		}
	}
	
	for (int i = 0; i<n; i++) {
		int ocurr = 1;
		for (int j = i+1; j<n; j++) {
			if (x[i] == x[j]) {
				ocurr++;
			}
		}
		
		if (ocurr > maxocurr) {
			maxocurr = ocurr;
			repetidos = 1;
			max = x[i];
		} else if (ocurr == maxocurr) {
			repetidos++;
		}
	}
	
	if (repetidos == 1) {
		cout<<"El valor "<<max<<" ocurre "<<maxocurr<<" veces."<<endl;
	} else {
		cout<<"El maximo de ocurrencias ("<<maxocurr<<") se repite "<<repetidos<<" veces."<<endl;
	}
	
	return 0;
}
