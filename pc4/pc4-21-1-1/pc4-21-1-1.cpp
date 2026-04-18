#include<iostream>
#include<fstream>

using namespace std;

struct alumno {
	char codigo[10];
	char apellidos[20];
	char nombres[20];
	int notaparcial;
} talumno;

int main() {
	char op;
	cout<<"w: Escritura, r: lectura y operacion: ";cin>>op;
	if (op == 'w' or op == 'W') {
		ofstream a("lista.dat", ios::out|ios::binary);
		int n = 0;
		do {
			cout<<"n: ";cin>>n;
		} while (n<=0);
		
		for (int i = 0; i<n; i++) {
			cout<<"Alumno "<<i+1<<endl;
			cout<<"Codigo: ";cin.ignore();cin.getline(talumno.codigo, 10);
			cout<<"Apellidos: ";cin.ignore();cin.getline(talumno.apellidos, 20);
			cout<<"Nombres: ";cin.ignore();cin.getline(talumno.nombres, 20);
			
			do {
				cout<<"Nota del parcial: ";cin>>talumno.notaparcial;
				cin.ignore();
			} while (talumno.notaparcial<0 or talumno.notaparcial>20);
			cout<<endl;
			
			a.write(reinterpret_cast<char *>(&talumno), sizeof(alumno));
		}
		a.close();
	} else {
		ifstream ar("lista.dat", ios::in|ios::binary);
		int i = 0;
		while (ar.read(reinterpret_cast<char *>(&talumno), sizeof(alumno))) {
			if (talumno.notaparcial <=5) {
				cout<<"Alumno "<<i+1<<" (posicion "<<i<<"):"<<endl;
				cout<<"Codigo: "<<talumno.codigo<<endl;
				
			}
			
			
			i++;
		}
		ar.close();
		
	}
}