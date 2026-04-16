#include<iostream>
#include<fstream>
using namespace std;

int main() {
	char r;
	struct reg_agenda {
		char nombre[30], direccion[50], telefono[10];
	} ragenda;
	ofstream a("Agenda.dat", ios::out|ios::binary);
	do {
		cout<<"Nombre: "; gets(ragenda.nombre);
		cout<<"Direccion: ";gets(ragenda.direccion);
		cout<<"Telefono: ";gets(ragenda.telefono);
		a.write(reinterpret_cast<char *>(&ragenda), sizeof(reg_agenda));
		cout<<"Agregar otro? (S/N)";
		cin>>r;
		getchar();
	} while (r == 'S' or r == 's');
	a.close();
	return 0;
}