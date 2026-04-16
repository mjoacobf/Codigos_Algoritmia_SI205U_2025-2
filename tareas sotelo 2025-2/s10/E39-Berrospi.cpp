#include<iostream>
#include<fstream>

using namespace std;

int main() {
	ifstream archivo("Datos.txt");
	int s = 0;
	int n = 0;
	int max = 0;
	int min = 0;
	string num;
	while (getline(archivo, num)) {
		
		int numero = 0;
		
		
		for (int i = 0; i<num.size(); i++) {
			int cif = num[i] - '0';
			numero*=10;
			numero+=cif;
		}
		s+=numero;
		n++;
		
		if (n == 1) {
			max = numero;
			min = numero;
		} else {
			if (numero > max) max = numero;
			if (numero < min) min = numero;
		}
	}
	archivo.close();
	float prom = s*1.0/n;
	cout<<"Prom: "<<prom<<endl;
	cout<<"Max: "<<max<<endl;
	cout<<"Min: "<<min<<endl;
	
	
	return 0;
}
