#include<iostream>

using namespace std;

int main() {
	int n = 0;
	do {
		cout<<"Ingrese la cantidad de numeros a analizar: ";cin>>n;
	} while (n<=0);
	
	int x[2*n];
	
	for (int i = 0; i<n; i++) {
		int e = 0;
		do {
		cout<<"Ingrese el numero "<<i+1<<" (2-3 cifras): ";cin>>e;
		} while (e<10 or e>999);
		x[i] = e;
	}
	
	//eliminar duplicados
	
	for (int i = 0; i<n; i++) {
		for (int j = i+1; j<n; j++) {
			if (x[i]==x[j]) {
				for (int k = i; k<n-1; k++) {
					x[k] = x[k+1];
				}
				i--;
				n--;
				j = n;
			}
		}
	}
	
	cout<<"Luego de la eliminacion: "<<endl;
	int s = 0;
	for (int i = 0; i<n; i++) {
		s+=x[i];
		cout<<x[i]<<" ";
	}
	cout<<endl;
	float prom = s*1.0/n;
	cout<<"Promedio: "<<prom<<endl;
	
	//duplicacion
	for (int i = 0; i<n; i++) {
		bool primo = true;
		for (int m = 2; m<x[i]; m++) {
			if (x[i]%m == 0) primo = false;
		}
		
		if (primo and x[i]*1.0 > prom) {
			for (int j = n; j>i; j--) {
				x[j] = x[j-1];
			}
			i++;
			n++;
		}
	}
	
	cout<<"Luego de la duplicacion: "<<endl;
	for (int i = 0; i<n; i++) {
		cout<<x[i]<<" ";
	}
	
	return 0;
}
