#include<iostream>
#include<fstream>
using namespace std;

int main() {
	struct reg_agenda {
		char nombre[30], direccion[50], telefono[10];
	} ragenda;
	int i = 0;
	ifstream a("Agenda.dat", ios::in|ios::binary);
	while (!a.eof()) {
		a.read(reinterpret_cast<char *>(&ragenda), sizeof(reg_agenda));
		
		if (!a.fail()) {
			
			cout<<"Nombre: "<<ragenda.nombre<<endl;
			cout<<"Direccion: "<<ragenda.direccion<<endl;
			cout<<"Telefono: "<<ragenda.telefono<<endl;
			cout<<endl;
		}
	}

	a.close();
	return 0;
}