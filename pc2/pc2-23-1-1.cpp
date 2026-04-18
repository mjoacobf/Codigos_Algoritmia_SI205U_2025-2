#include<iostream>

using namespace std;

int main() {
	int n = 0;
	int m = 0;
	
	do {
		cout<<"Ingrese la cantidad de platos: ";cin>>n;
	} while (n<=0);
	
	do {
		cout<<"Ingrese la cantidad de insumos: ";cin>>m;
	} while (m<=0);
	
	int insumos[m][n];
	
	for (int i = 0; i<m; i++) {
		for (int j = 0; j<n; j++) {
			int e = -1;
			do {
				cout<<"Ingrese la cantidad en gramos del insumo "<<i+1<<" en el plato "<<j+1<<": ";cin>>e;
			} while (e<0);
			
			insumos[i][j] = e;
		}
	}
	
	float costos[m];
	for (int i =0;i<m;i++) {
		float e = 0;
		do {
			cout<<"Ingrese el costo del insumo "<<i+1<<": ";cin>>e;
		} while (e<=0);
		costos[i] = e;
	}
	
	float preciolista[n] = {0};
	int id[n];
	for (int j = 0; j<n; j++) {
		id[j] = j+1;
	}
	
	for (int j = 0; j<n;j++) {
		for (int i = 0; i<m;i++) {
			preciolista[j] += insumos[i][j]*costos[i];
		}
		preciolista[j];
	}
	
	for (int i = 0; i<n;i++) {
		for (int j = n-1; j>i;j--) {
			if (preciolista[i] > preciolista[j]) {
				int t1 = preciolista[j];
				preciolista[j] = preciolista[i];
				preciolista[i] = t1;
				
				int t2 = id[j];
				id[j] = id[i];
				id[i] = t2;
			}
		}
	}
	
	
	cout<<"Plato\tCosto"<<endl;
	for (int i = 0; i<n; i++) {
		cout<<id[i]<<"\t"<<preciolista[i]/1000<<endl;
	}
	
	return 0;
}