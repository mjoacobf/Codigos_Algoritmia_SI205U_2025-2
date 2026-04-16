#include<iostream>

using namespace std;

int main() {
	int n1, n2, n3, n4, n5, n6;
	cout<<"Ingrese seis numeros: "<<endl;cin>>n1>>n2>>n3>>n4>>n5>>n6;
	while (!(n1 <= n2 and n2 <= n3 and n3 <= n4 and n4 <= n5 and n5 <= n6)) {
		if (n1 > n2) {
			int t = n2;
			n2 = n1;
			n1 = t;
		};
		if (n2 > n3) {
			int t = n3;
			n3 = n2;
			n2 = t;
		};
		if (n3 > n4) {
			int t = n4;
			n4 = n3;
			n3 = t;
		};
		if (n4 > n5) {
			int t = n5;
			n5 = n4;
			n4 = t;
		};
		if (n5 > n6) {
			int t = n6;
			n6 = n5;
			n5 = t;
		};
	}
	
	cout<<"El mayor numero es "<<n6<<endl;
	
	
	return 0;
}
