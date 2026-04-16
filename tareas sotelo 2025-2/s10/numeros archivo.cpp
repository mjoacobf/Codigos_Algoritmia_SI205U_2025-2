#include<iostream>
#include<fstream>

using namespace std;

int main() {
	ofstream a("datos2.txt");
	int num, i, n;
	cout<<"Ingrese el numero de datos: ";cin>>n;
	for (i = 0; i<n; i++) {
		cout<<i+1<<": ";cin>>num;
		if (i<n-1) {
			a<<num<<endl;
		} else {
			a<<num;
		}
	}
	
	a.close();
	
	
	
	
	
	
	return 0;
}
