#include<iostream>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	for (int i = 2; i<=9; i++) {
		int t = n;
		
		int conteo = 1;
		int numeroConvertido = 0;
		
		while (t>0) {
			int r = t%i;
			
			numeroConvertido+=conteo*r;
			conteo*=10;
			t/=i;
		}
		
		t = numeroConvertido;
		int inversaConvertido = 0;
		while (t>0) {
			int c = t%10;
			inversaConvertido*=10;
			inversaConvertido+=c;
			t/=10;
		}
		
		if (inversaConvertido == numeroConvertido) {
			cout<<"Base "<<i<<" donde el numero es "<<numeroConvertido<<endl;
		}
	}
	
	
	return 0;
}