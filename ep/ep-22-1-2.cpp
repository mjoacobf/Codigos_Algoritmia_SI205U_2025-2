#include<iostream>

using namespace std;

int main() {
	int n = 0;
	do {
		cin>>n;
	} while (n<=0);
	
	for (int i = 2; i<10; i++) {
		int num = 0;
		int conteo = 1;
		int cifras = 0;
		int t = n;
		while (t>0) {
			int c1 = t%i;
			num+=c1*conteo;
			conteo*=10;
			t-=c1;
			t/=i;
			cifras++;
		}
		
		int numero[cifras];
		t = num;
		for (int i = cifras-1; i>=0; i--) {
			int c = t%10;
			numero[i] = c;
			t/=10;
		}
		
		bool es = true;
		for (int i = 0; i<cifras/2; i++) {
			if (numero[i] != numero[cifras-1-i]) es = false;
		}
		
		
		if (es) {
			cout<<"El numero es capicua en la base "<<i<<" ("<<num<<")."<<endl;
		}
	}
	
	return 0;
}