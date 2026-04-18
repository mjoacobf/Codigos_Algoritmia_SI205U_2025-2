#include<iostream>

using namespace std;

int main() {
	int n = 0;
	do {
		cout<<"Ingrese la cantidad de asteriscos por lado (3<n<20): ";cin>>n;
	} while (n<=3 or n>=20);
	
	for (int i = 1; i<=n;i++) {
		for (int j = 1; j<=n;j++) {
			if (i == 1 or i == n) {
				cout<<"*";
			} else {
				if (j == 1 or j == n) {
					cout<<"*";
				} else cout<<" ";
			}
		}
		cout<<endl;
	}
	
	
	
	
	
	
	return 0;
}