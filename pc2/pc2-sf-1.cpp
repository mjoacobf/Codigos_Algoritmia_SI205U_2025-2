#include<iostream>

using namespace std;

bool esprimo(int num) {
	
	if (num == 1) return false;
	for (int k = 2; k<num; k++) {
		if (num%k==0) return false;
	}

	return true;
}

bool escapicua(int num) {
	int cifras = 0;
	int t = num;
	while (t>0) {
		cifras++;
		t/=10;
	}
	
	if (cifras == 2) {
		if (num%10 == num/10) return true;
	} else if (cifras == 3) {
		if (num%10 == num/100) return true;
	}
	
	return false;
}


int main() {
	int arreglo[100] = {1};
	
	for (int i = 0; i<50; i++) {
		int e;
		cout<<"Ingrese el numero "<<i+1<<" de 50 (desde 10 hasta 999, fuera del rango hace que se detenga): ";cin>>e;
		if (e < 10 or e>999) break;
		arreglo[i] = e;
	}

	//Eliminacion de primos
	for (int i = 0; i<50; i++) {
		cout<<arreglo[i];
		if (esprimo(arreglo[i])) {
			cout<<"esoaranin"<<arreglo[i]<<endl;
			for (int j = i; j<50; j++) {
				arreglo[j] = arreglo[j+1];
			}
		}
		i--;
	}
	
	//Duplicacion de capicuas
	for (int i = 0; i<100; i++) {
		
		if(escapicua(arreglo[i])) {
			for(int j = 99; j>i; j--) {
				arreglo[j] = arreglo[j-1];
			}
		}
	}
	
	cout<<"Arreglo: "<<endl;
	
	for (int i = 0; i<100; i++) {
		if (arreglo[i] == 1) break;
		cout<<arreglo[i]<<" ";
	}
	
	return 0;
}