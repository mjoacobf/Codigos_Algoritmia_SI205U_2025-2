#include<iostream>

using namespace std;

int main() {
	int n = 0;
	
	do {
		cout<<"n: ";cin>>n;
	} while (n<1);
	
	int codigo[n][100];
	int cant[n] = {0};
	
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<100; j++) {
			int a;
			cout<<"Facultad "<<i+1<<" alumno (0 o negativo: finalizar) "<<j+1<<": ";cin>>a;
			
			if (a <=0) {
				a = 0;
				codigo[i][j] = 0;
				j = 100;
			} else {
				codigo[i][j] = a;
				cant[i]++;
			}
		}
	}
	
	// Ordenamiento
	
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<cant[i]; j++) {
			for (int k = cant[i]-1; k>j; k--) {
				if (codigo[i][j] > codigo[i][k]) {
					int t = codigo[i][k];
					codigo[i][k] = codigo[i][j];
					codigo[i][j] = t;
				}
			}
		}
	}
	
	//Imprimir
	
	for (int i = 0; i<n; i++) {
		cout<<"Facultad "<<i+1<<": "<<endl;
		int actual;
		int conteo = 1;
		for (int j = 0; j<cant[i]; j++) {	
			if (j==0) {
				actual = codigo[i][j];
				cout<<actual<<"\t";
			}
			else {
				if (codigo[i][j] == actual) conteo++;
				else {
					cout<<conteo<<endl;
					actual = codigo[i][j];
					cout<<actual<<"\t";
					conteo = 1;
				}
			}
		}
		cout<<conteo<<endl; //creo que esto se puede arreglar
		
	}
	
	return 0;
}