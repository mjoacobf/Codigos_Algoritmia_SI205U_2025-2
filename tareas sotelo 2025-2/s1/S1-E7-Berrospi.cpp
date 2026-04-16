#include<iostream>

using namespace std;
int main() {
	int n = 0;
	int cifraspares = 0;
	int cifrasimpares = 0;
	
	do {
		cout<<"Ingrese un numero entero positivo: ";cin>>n;
	} while (n<= 0);
	
	int t = n;
	
	while (t>0) {
		int cifra = t%10;
		if (cifra%2 == 0) cifraspares++;
		else cifrasimpares++;
		
		t/=10;
	}
	
	int cifras = cifraspares + cifrasimpares;
	
	cout<<"El numero tiene "<<cifras<<" cifras.";
	if (cifraspares != 0) cout<<"El numero tiene "<<cifraspares<<" cifras pares.";
	else cout<<"El numero no tiene cifras pares";
	
	if (cifrasimpares != 0) cout<<"El numero tiene "<<cifrasimpares<<" cifras impares.";
	else cout<<"El numero no tiene cifras impares";
	
	return 0;
}
