#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int main() {
	srand(time(NULL));
	int n = 0;
	do {
		cout<<"Ingrese el orden de la matriz: ";cin>>n;
	} while (n<=0);
	
	int inicio = n/4;
	int fin = 3*n/4;
	
	int x[n][n];
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			x[i][j] = 1 + rand()%100;
		}
	}
	
	cout<<"La matriz es : "<<endl;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			cout<<x[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	int total = (fin-inicio+1)*(fin-inicio+1);
	int sonvalores = 0;
	
	for (int i = inicio; i<=fin; i++) {
		for (int j = inicio; j<=fin; j++) {
			int c = x[i][j];
			
			int x0 = 1;
			int x = 1;
			while (x<c) { //fibonacci
				int t = x;
				x = x+x0;
				x0 = t;
			}
			
			if (x == c) {
				sonvalores++;
			}
		}
	}
	float porc = sonvalores*100.0/total;
	cout<<"Porcentaje: "<<porc<<"%";
	
	
	return 0;
}
