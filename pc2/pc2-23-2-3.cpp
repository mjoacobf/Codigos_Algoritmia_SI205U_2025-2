#include<iostream>

using namespace std;

int main() {
	int n1 = 0;
	int n2 = 0;
	int cif1 = 0;
	int cif2 = 0;
	
	do {
		cout<<"Ingrese el primer numero (al menos 6 cifras): ";cin>>n1;
	} while (n1 < 100000);
	
	do {
		cout<<"Ingrese el segundo numero (al menos 6 cifras): ";cin>>n2;
	} while (n2 < 100000);
	
	int t = n1;
	while (t>0) {
		cif1++;
		t/=10;
	}
	
	t = n2;
	while (t>0) {
		cif2++;
		t/=10;
	}
	
	int PRIMERO[cif1];
	int SEGUNDO[cif1+cif2];
	
	for (int i = cif1-1; i>=0; i--) {
		PRIMERO[i] = n1%10;
		n1/=10;
	}
	
	for (int i = cif2-1; i>=0; i--) {
		SEGUNDO[i] = n2%10;
		n2/=10;
	}
	
	while (cif1 > 0) {
		if (PRIMERO[0]%2 == 1) {
			for (int i = cif2; i>0; i--) {
				SEGUNDO[i] = SEGUNDO[i-1];
			}
			SEGUNDO[0] = PRIMERO[0];
		} else {
			SEGUNDO[cif2] = PRIMERO[0];
		}
		
		for (int i = 0; i<cif1-1; i++) {
			PRIMERO[i] = PRIMERO[i+1];
		}
		cif1--;
		cif2++;
	}
	
	for (int i = 0; i<cif2; i++) {
		cout<<SEGUNDO[i];
	}
	
	return 0;
}
