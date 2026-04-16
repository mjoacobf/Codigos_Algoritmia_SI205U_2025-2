#include<iostream>

using namespace std;


int main() {
	int n = 0;
	int sum = 0;
	do {
		cout<<"Ingrese el orden de la matriz (impar y mayor o igual que 5): ";cin>>n;
	} while (n<5 or n%2 == 0);
	
	int x[n][n];
	
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			cout<<"Ingrese el numero "<<i+1<<": ";cin>>x[i][j];
			
			if (i == j or i + j == n-1) {
				sum+=x[i][j];
			}
		}
	}
	
	cout<<"La suma es "<<sum;
	return 0;
}
