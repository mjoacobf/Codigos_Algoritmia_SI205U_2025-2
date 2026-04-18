#include<iostream>

using namespace std;


int sumacifras(int num) {
	int sum = 0;
	while (num>0) {
		sum+=num%10;
		num/=10;
	}
	
	return sum;
}

int main() {
	int n = 0;
	
	do {
		cout<<"Ingrese la cantidad de numeros a analizar: ";cin>>n;
	} while (n<=0);
	
	int numeros[n];
	
	for (int i = 0; i<n; i++) {
		int e = 0;
		do {
			cout<<"Ingrese el numero "<<i+1<<": ";cin>>e;
		} while (e<=0);
		
		numeros[i] = e;
	}
	
	
	for (int i = 0; i<n-1;i++) {
		if (sumacifras(numeros[i])<sumacifras(numeros[i+1])) {
			int t = numeros[i+1];
			numeros[i+1] = numeros[i];
			numeros[i] = t;
			
			i = -1;
		} else if (sumacifras(numeros[i])==sumacifras(numeros[i+1])) {
			if (numeros[i] < numeros[i+1]) {
				int t = numeros[i+1];
				numeros[i+1] = numeros[i];
				numeros[i] = t;
			}
		}
	}
	
	for (int i = 0; i<n; i++) {
		cout<<numeros[i]<<endl;
	}
	
	
	
	
	
	
	return 0;
}