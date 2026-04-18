#include<iostream>

using namespace std;

int main() {
	int n = 0;
	do {
		cout<<"Ingrese la cantidad de alumnos: ";cin>>n;
	} while (n<=0);
	
	int notas[n];
	bool existe20 = false;
	int aprobados = 0;
	
	for (int i = 0; i<n; i++) {
		int e = -1;
		do {
			cout<<"Ingrese la nota "<<i+1<<": ";cin>>e;
		} while (e<0 or e>20);
		
		notas[i] = e;
		if (e == 20) existe20 = true;
		if (e>=10) aprobados++;
	}
	
	float xaprob = aprobados*1.0/n;
	
	for (int i = 0; i<n; i++) {
		cout<<notas[i]<<"\t";
	}
	cout<<xaprob*100.0<<"% de aprobados."<<endl;
	
	while (xaprob < 0.7 and not existe20) {
		aprobados = 0;
		for (int i = 0; i<n; i++) {
			notas[i]++;
			if (notas[i] == 20) existe20 = true;
			if (notas[i]>=10) aprobados++;
			cout<<notas[i]<<"\t";
		}
		
		xaprob = aprobados*1.0/n;
		cout<<xaprob*100.0<<"% de aprobados."<<endl;
	}
	
	
	return 0;
}