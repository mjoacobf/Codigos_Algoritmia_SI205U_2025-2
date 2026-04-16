#include<iostream>

using namespace std;

int main() {
	int n, Mpar = 1,mimpar=0;
	cout<<"Ingrese la cantidad de numeros a escribir: "<<endl;cin>>n;
	
	for (int i = 1; i<=n;i++) {
		int e;
		cout<<"Ingrese el numero "<<i<<": ";cin>>e;
		if (e%2 == 0){
			if (Mpar ==1 or Mpar < e) Mpar = e;	
		} ;
		if (e%2 != 0) {
			if (mimpar == 0 or e < mimpar) mimpar = e;
		}
	}
	
	
	if (Mpar == 1) cout<<"No se introdujo ningun numero par."<<endl; else cout<<"El mayor numero par es "<<Mpar<<endl;
	if (mimpar == 0) cout<<"No se introdujo ningun numero impar."<<endl; else cout<<"El menor numero impar es "<<mimpar<<endl;
	
	
	return 0;
	
}
