#include<iostream>
#include<fstream>
using namespace std;

int main() {
	int e;
	ifstream a("numeros.dat", ios::in|ios::binary);
	while (a.read(reinterpret_cast<char *>(&e), sizeof(e))) {
		cout<<e<<endl;
	}
	a.close();
	return 0;
}