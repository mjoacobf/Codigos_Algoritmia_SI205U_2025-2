#include<iostream>

using namespace std;

bool esprimo(int num) {
	if (num == 1) return false;
	for (int k = 2; k<num; k++) {
		if (num%k==0) {
			return false;
		}
	}
	return true;
}

int main() {
	int n = 0;
	int apariciones[10] = {0};
	do {
		cout<<"Ingrese la cantidad de numeros a analizar: ";cin>>n;
	} while (n<=0);
	
	for (int i = 0; i<n;i++) {
		int e = 0;
		
		do {
			cout<<"Ingrese el numero "<<i+1<<"(positivo): ";cin>>e;
		} while (e<=0);
		
		if (esprimo(e)) {
			while (e>0) {
				int c = e%10;
				apariciones[c]++;
				e/=10;
			}
		}
	}
	
	for (int i = 0; i<=9; i++) {
		if (apariciones[i] > 0) {
			cout<<"El digito "<<i<<" aparece "<<apariciones[i]<<" veces."<<endl;
		}
	}
	
	return 0;
}