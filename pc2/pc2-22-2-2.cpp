#include<iostream>

using namespace std;

bool esprimo(int numero) {

	if (numero == 1) return false;
	for (int k = 2; k<numero;k++) {
		if (numero%k == 0) {
			return false;
		}
	}
	return true;
}


int main() {
	int suma = 0;
	int n = 0;
	do {
		cout<<"Ingrese el orden de la matriz (impar y mayor que 2): ";cin>>n;
	} while (n%2 == 0 or n<= 2);
	
	int matriz[n][n];
	
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			cout<<"Indique el elemento ("<<i+1<<";"<<j+1<<"): ";cin>>matriz[i][j];
		}
	}
	
	
	for (int i = 0; i<n;i++) {
		for (int j = 0; j<n; j++) {
			bool c1 = j<i and i+j<n-1;
			bool c2 = j>i and i+j>n-1;
			if (c1 or c2) {
				if (esprimo(matriz[i][j])) {
					suma+=matriz[i][j];
				}
			}
		}
	}
	
	
	
	cout<<suma;
	
	
	
	return 0;
}
/*
7
3
7
15
36
59
8
4
5
11
8
3
13
3
38
14
4
10
11
10
12
19
4
17
3
16
4
11
6
12
4
5
21
13
8
18
8
2
4
9
19
1
23
15
31
12
43
16
29
12
*/