#include<iostream>

using namespace std;

void maxminprom(int x[], int n, int &max, int &min, float &prom) {
	max = x[0];
	min = x[0];
	prom = 0;
	
	for (int i = 0; i<n; i++) {
		if (x[i]<min) min = x[i];
		if (x[i]>max) max = x[i];
		prom+=x[i];
	}
	
	prom*=1.0;
	prom/=n;
}

int main() {
	int a[100], n, max = 1000, min = 100;
	float prom = 3.8;
	cout<<"Ingrese la cantidad de numeros: ";cin>>n;
	for (int i = 0; i<n; i++) {
		cout<<"a["<<i<<"]: ";cin>>a[i];
	}
	
	cout<<"Inicialmente: "<<endl;
	cout<<"Max: "<<max<<endl;
	cout<<"Min: "<<min<<endl;
	cout<<"Prom: "<<prom<<endl;
	
	maxminprom(a, n, max, min, prom);
	
	cout<<"Despues: "<<endl;
	cout<<"Max: "<<max<<endl;
	cout<<"Min: "<<min<<endl;
	cout<<"Prom: "<<prom<<endl;
	
	return 0;
}
