#include<iostream>

using namespace std;

int main() {
	int n = 0;
	bool simetrica = true;
	do {cout<<"Ingrese el orden de la matriz: ";cin>>n;} while (n<=0);
	
	int x[n][n];
	
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			cout<<"Ingrese el valor en ("<<i+1<<";"<<j+1<<"): ";cin>>x[i][j];
			
			if (i > j) {
				if (x[i][j] != x[j][i]) {
					simetrica = false;
					i = n;
					j = n;
				}
			}
		}
	}
	
	if (not simetrica) {
		cout<<"La matriz no es simetrica.";
	} else {
		cout<<"La matriz es simetrica.";
	}
	
	return 0;
}
