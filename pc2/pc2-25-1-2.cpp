#include<iostream>

using namespace std;

int main() {
	int n = 0;
	int x[100];
	do {
		cout<<"n (<=50): "; cin>>n;
	} while (n<=0 or n>50);
	
	int sum = 0;
	
	for (int i = 0; i<n; i++) {
		int e = 0;
		do {
			cout<<"x["<<i<<"] (2 a 3 cifras): ";cin>>e;
		} while (e < 10 or e > 999);
		
		x[i] = e;
		sum+=e;
	}
	
	float prom = sum*1.0/n;
	cout<<"Prom: "<<prom<<endl;
		
	//Eliminacion de pares menores al promedio
	for (int i = 0; i<n; i++) {
		if (x[i]%2 == 0 and x[i]*1.0 < prom) {
			for (int j = i; j<n; j++) {
				x[j] = x[j+1];
			}
			n--;
			i--;
		}
	}
	
	//Duplicacion de primos mayores al promedio
	for (int i = 0; i<n; i++) {
		bool primo = true;
		for(int k = 2; k<x[i]; k++) {
			if (x[i]%k == 0) primo = false;
		}
		
		if (x[i]%2 == 1 and primo and x[i]*1.0 > prom) {
			for(int j = n; j>i; j--) {
				x[j] = x[j-1];
			}
			n++;
			i++;
		}
	}
	
	for (int i = 0; i<n; i++){
		cout<<x[i]<<" ";
	}
	
	
	
	
	
	return 0;
}