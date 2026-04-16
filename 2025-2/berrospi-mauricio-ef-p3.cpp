#include<iostream>
#include<fstream>

using namespace std;

int contardigitos(string x) {
	int i = 0;
	while (x[i]!='\0') i++;
	return i;
}

//se trata de multiplicar un numero solamente por un digito

void producto(int aa[], int bb[], int num, int prod[], int ia, int length, int pos) {
	if (pos==-1) return;
	int pp[ia+1];
	for (int i = 0; i<ia+1; i++) {
		pp[i]=0;
		}
	
		for (int i = ia-1; i>=0; i--) {
			int p = aa[i]*num;
			int r = p/10;
			p = p%10;
			pp[i+1]=p;
			pp[i]+=r;
		}
	cout<<"Producto parcial:"<<endl;
	for (int i = 0; i<ia+1; i++) {
		cout<<pp[i];
		}
		
		cout<<endl;
	
	for (int i = 0; i<ia; i++) {
		prod[length-i-1]+=pp[ia-i];
	}
	
	
	
	producto(aa, bb, bb[pos-1], prod, ia, length-1, pos-1);
	
}

int main() {
	string a;
	string b;
	cin>>a>>b;
	
	int ia = contardigitos(a);
	int ib = contardigitos(b);
	
	int aa[ia];
	
	for (int i = 0; i<ia; i++) {
		aa[i] = a[i]-'0';
	}
	
	int bb[ib];
	
	for (int i = 0; i<ib; i++) {
		bb[i] = b[i]-'0';
	}

	int prod[ia+ib] = {0};
	
	producto(aa, bb, bb[ib-1],prod,ia,ia+ib, ib-1);
	
	for (int i = 0; i<ia+ib; i++) {
		cout<<prod[i];
	}
	
	return 0;
}