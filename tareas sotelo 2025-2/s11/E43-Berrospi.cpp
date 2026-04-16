#include<iostream>
#include<fstream>
using namespace std;

int main() {
	char o;
	int e;
	
	cout<<"Opciones: leer (l), escribir (e): ";cin>>o;
	if (o == 'l' or o == 'L') {
		ifstream a("numeros.dat", ios::in|ios::binary);
		while (a.read(reinterpret_cast<char *>(&e), sizeof(e))) {
			cout<<e<<endl;
		}
		a.close();
	} else {
		int n = 0;
		do {
			cout<<"Cantidad de numeros a agregar: ";cin>>n;
		} while (n<=0);
		ofstream a("numeros.dat", ios::out|ios::binary);
		for (int i = 0; i<n; i++) {
			cout<<"Numero "<<i+1<<": ";cin>>e;
			a.write(reinterpret_cast<char *>(&e), sizeof(e));
		}
			
		a.close();
	}
	
	return 0;
}