#include<iostream>

using namespace std;

int main() {
	int n;
	int cifraspares = 0;
	int cifrasimpares = 0;
	
	cout<<"Ingrese un numero entero positivo: ";cin>>n;
	
	while (n > 0) {
		int c = n%10;
		if (c%2 == 0) cifraspares++;
		else cifrasimpares++;
		
		n/=10;
	}
	
	int cifras = cifrasimpares + cifraspares;
	
	cout<<"El numero tiene "<<cifras<<" cifras, de las cuales "<<cifrasimpares<<" son impares y "<<cifraspares<<" son pares."<<endl;
	
	
	
	
}
