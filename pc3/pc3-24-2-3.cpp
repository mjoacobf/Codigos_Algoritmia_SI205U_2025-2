#include<iostream>

using namespace std;

int decimal(int num) {
	int nuevo = 0;
	int c = 1;
	
	while (num>0) {
		int cifra = num%2;
		nuevo+=cifra*c;
		c*=10;
		num-=cifra;
		num/=2;
	}
	
	return nuevo;
}

void prod(int p[], int n, int num) {
	int d = decimal(num);
	for (int i = 0; i<n; i++) {
		p[i] = d%10;
		d/=10;
	}
}

void sumas(int x[], int n) {
	for (int i = 1; i<n*n; i++) {
		int sum = 0;
		int p[n];
		prod(p, n, i);
		
		for (int j = 0; j<n; j++) {
			sum+=x[j]*p[j];
		}
		
		cout<<decimal(i)<<": "<<sum<<endl;
	}
}

int main() {
	int n = 0;
	do {
		cin>>n;
	} while (n<=1);
	int x[n];
	for (int i = 0; i<n; i++){
		cout<<"x["<<i<<"]: ";cin>>x[i];
	}
	
	sumas(x,n);
}