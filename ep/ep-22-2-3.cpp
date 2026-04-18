#include<iostream>

using namespace std;

int eliminarcifra(int num, int d) {
	int newnum = 0;
	int temp = num;
	int count = 1;
	
	while (temp > 0) {
		int cif = temp%10;
		if (cif != d) {
			newnum+= cif*count;
			count*=10;
		}
		
		temp/=10;
	}
	
	return newnum;
}

int main() {
	int n = 0;
	do {
		cout<<"n > 999: ";cin>>n;
	} while (n<1000);
	
	int cifras = 0;
	
	int apariciones[10] = {0};
	
	int t = n;
	while (t>0) {
		int c = t%10;
		apariciones[c]++;
		t/=10;
		cifras++;
	}
	
	int maxapar = -1;
	int vmax = 0;
	int	conteo=10;
	
	for (int i = 0; i<10; i++) {
		if (i == 0) {
			maxapar = apariciones[i];
			
		}
		if (maxapar < apariciones[i]) {
			maxapar = apariciones[i];
			conteo = 10;
			vmax = i;
		} else if (maxapar == apariciones[i]) {
			vmax+=conteo*i;
			conteo*=10;
		}
	}
	
	if (maxapar > 1) {
		cout<<"Cifras a eliminar: ";
		while (vmax>0) {
			int c = vmax%10;
			cout<<c<<" ";
			
			n = eliminarcifra(n, c);
			
			vmax/=10;
		}
	}
	
	cout<<endl<<n;
	
	
	
	
	
	return 0;
}