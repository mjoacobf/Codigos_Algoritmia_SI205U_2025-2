#include<iostream>

using namespace std;

int main() {
	int n1,n2,n3;
	
	cin>>n1>>n2>>n3;
	
	int digitosComunes = 0;
	int cantComunes = 0;
	
	//Hallando digitos en comun
	for (int i = 9;i>=0;i--) {
		int t1 = n1;
		int t2 = n2;
		int t3 = n3;
		
		bool comun1 = false;
		bool comun2 = false;
		bool comun3 = false;
		
		while (t1>0) {
			int c = t1%10;
			if (c == i) {
				comun1 = true;
				break;
			}
			t1/=10;
		}
		
		while (t2>0) {
			int c = t2%10;
			if (c == i) {
				comun2 = true;
				break;
			}
			t2/=10;
		}
		
		while (t3>0) {
			int c = t3%10;
			if (c == i) {
				comun3 = true;
				break;
			}
			t3/=10;
		}
		
		if (comun1 and comun2 and comun3) {
			cantComunes++;
			digitosComunes*=10;
			digitosComunes+=i;
		}
	}
	
	//Calculando el resultado
	int new1 = 0;
	int new2 = 0;
	int new3 = 0;
	
	int t1 = n1;
	int t2 = n2;
	int t3 = n3;
	
	int conteo = 1;
	
	while (t1 > 0) {
		int c = t1%10;
		bool esComun = false;
		int copiaDigitos = digitosComunes;
		for (int i = 1; i<=cantComunes; i++) {
			int c2 = copiaDigitos%10;
			if (c == c2) {
				esComun = true;
			}
			
			copiaDigitos/=10;
		}
		
		if (not esComun) {
			new1+=conteo*c;
			conteo*=10;
		}
		
		t1/=10;
	}
	
	conteo = 1;
	
	while (t2 > 0) {
		int c = t2%10;
		bool esComun = false;
		int copiaDigitos = digitosComunes;
		for (int i = 1; i<=cantComunes; i++) {
			int c2 = copiaDigitos%10;
			if (c == c2) {
				esComun = true;
			}
			
			copiaDigitos/=10;
		}
		
		if (not esComun) {
			new2+=conteo*c;
			conteo*=10;
		}
		
		t2/=10;
	}
	
	conteo = 1;
	
	while (t3 > 0) {
		int c = t3%10;
		bool esComun = false;
		int copiaDigitos = digitosComunes;
		for (int i = 1; i<=cantComunes; i++) {
			int c2 = copiaDigitos%10;
			if (c == c2) {
				esComun = true;
			}
			
			copiaDigitos/=10;
		}
		
		if (not esComun) {
			new3+=conteo*c;
			conteo*=10;
		}
		
		t3/=10;
	}
	
	cout<<new1<<endl<<new2<<endl<<new3;
	
	
	
	return 0;
}



/*
476702
408937
34701
*/
