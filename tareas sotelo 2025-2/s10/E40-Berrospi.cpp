#include<iostream>
#include<fstream>

using namespace std;

int main() {
	ofstream a("Agenda.txt");
	string nombre, direccion, telefono;
	bool continuar = true;
	while (continuar) {
		cout<<"Nombre: "; getline(cin, nombre);
		if (nombre!="") {
			cout<<"Direccion: "; getline(cin,direccion);
			cout<<"Telefono: "; getline(cin, telefono);
			
			a<<nombre<<" "<<direccion<<" "<<telefono<<endl;
		} else continuar = false;
	}
	
	a.close();
	return 0;
}
