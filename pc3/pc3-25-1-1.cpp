#include<iostream>

using namespace std;

void SucesionCollatzMasLarga(int n, int &max, int &lmax) {
	max = 1;
	lmax = 0;
	
	for (int i = 1; i<=n; i++) {
		int v = i;
		int c = 1;
		while (v!=1) {
			if (v%2 == 0) v/=2;
			else {
				v*=3;
				v++;
			}
			c++;
		}
		
		cout<<i<<": "<<c<<endl;
		
		if (c > lmax) {
			max = i;
			lmax = c;
		}
	}
}

int main() {
	int n, max, lmax;
	do {
		cout<<"Ingrese n>0: ";cin>>n;
	} while (n<=0);
	
	SucesionCollatzMasLarga(n, max, lmax);
	
	cout<<"Mas larga: "<<max<<", con longitud "<<lmax<<endl;
	
	return 0;
}