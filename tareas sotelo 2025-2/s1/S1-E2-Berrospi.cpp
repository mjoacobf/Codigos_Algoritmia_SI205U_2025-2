#include<iostream>

using namespace std;

int main() {
	int n1, n2, n3;
	cout<<"Ingrese tres numeros: "<<endl;cin>>n1;cin>>n2;cin>>n3;
	
	while (!(n1 <= n2 and n2 <= n3)) {
		if (n1 > n2) {
			int t = n2;
			n2 = n1;
			n1 = t;
		}
		
		if (n2 > n3) {
			int t = n3;
			n3 = n2;
			n2 = t;
		}
	}
	
	if (n1 == n2 and n2 == n3) cout<<"Hay un empate entre los tres. El numero es "<<n1<<endl; 
	
	else cout<<"El mayor numero es "<<n3<<endl;
	
	
	return 0;
}
