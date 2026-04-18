#include<iostream>

using namespace std;

int main(){
	int b =0;
	
	do {
		cout<<"Ingrese la base (2-9): ";cin>>b;
	} while (b < 2 or b > 9);
	
	int n1 = 0;
	int n2 = 0;
	
	bool valid = true;
	
	do {
		cout<<"Ingrese el numero 1: ";cin>>n1;
		valid = true;
		int t = n1;
		if (t<n1) valid = false;
		while (t>0) {
			int c = t%10;
			if (c>=b) valid = false;
			t/=10;
		}
	} while (not valid);
	
	do {
		cout<<"Ingrese el numero 2: ";cin>>n2;
		valid = true;
		int t = n2;
		if (t<n2) valid = false;
		while (t>0) {
			int c = t%10;
			if (c>=b) valid = false;
			t/=10;
		}
	} while (not valid);
	
	int t = n1;
	int cifras1 = 0;
	while (t>0) {
		cifras1++;
		t/=10;
	}
	
	int num1[cifras1];
	t = n1;
	for (int i = cifras1-1; i>=0; i--) {
		num1[i] = t%10;
		t/=10;
	}
	
	int cifras2 = 0;
	t = n2;
	while (t>0) {
		cifras2++;
		t/=10;
	}
	
	int num2[cifras2];
	t = n2;
	for (int i = cifras2-1; i>=0; i--) {
		num2[i] = t%10;
		t/=10;
	}
	
	int producto[cifras1 + cifras2] = {0};
	
	for (int i = cifras2-1; i>=0; i--) {
		for (int j = cifras1-1; j>=0; j--) {
			producto[i+j+1] += num2[i]*num1[j];
		}
	}
	
	for (int i = cifras1 + cifras2 - 1; i>0; i--) {
		if (producto[i] >= b) {
			producto[i-1] += producto[i]/b;
			producto[i]%=b;
		}
	}
	cout<<"Producto: ";
	for (int i = 0; i<cifras1+cifras2; i++) {
		cout<<producto[i];
	}
	
	return 0;
}