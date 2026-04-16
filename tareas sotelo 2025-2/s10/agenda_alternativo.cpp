/*
Escribir un programa que permita ubicar los datos de una persona en un archivo de texto Agenda.txt. 
Debe pedir una cadena que representa a algun dato de la persona (Nombre, direccion o telefono) y 
buscar en el archivo los reglones de datos que contengan la cadena ingresada y mostrarlos en 
pantalla. De no encontrar coincidencia debe mostrar "Datos no encontrados". Luego debe preguntar 
si desea ubicar a otra persona, de ser asi debe volver a preguntar por la cadena a buscar y volver a 
explorar el archivo. De lo contrario terminar.
*/

#include<iostream>
#include<fstream>

using namespace std;

int main() {
	ifstream a("Agenda.txt");
	
	string cadena, subcadena, nombre;
	getline(cin, nombre);
	bool encontrado = false;
	for (int i = 0; i<nombre.length(); i++) nombre[i] = toupper(nombre[i]);
	
	while (getline(a,cadena)) {
		
		for (int i= 0; i<cadena.length(); i++) cadena[i]=toupper(cadena[i]);
		subcadena = "";
		int j = 0;
		for (int i = 0; i<cadena.length(); i++) {
			if (cadena[i]==nombre[j]) {
				subcadena+=nombre[j];
				j++;
			} else {
				if (subcadena == nombre) {
					encontrado = true;
					cout<<cadena<<endl;
					j = 0;
					subcadena = "";
					
				} else {
					j=0;
					subcadena="";
				}
			}
		}
	}

	if (!encontrado) cout<<"No encontrado"<<endl;
	char op;
	cout<<"De nuevo? (S/N): ";cin>>op;
	if (op != 'S' and op !='s') return 0;
	
	a.seekg(0);
	cin.ignore();
	getline(cin, nombre);
	encontrado = false;
	for (int i = 0; i<nombre.length(); i++) nombre[i] = toupper(nombre[i]);
	
	while (getline(a,cadena)) {
		
		for (int i= 0; i<cadena.length(); i++) cadena[i]=toupper(cadena[i]);
		subcadena = "";
		int j = 0;
		for (int i = 0; i<cadena.length(); i++) {
			if (cadena[i]==nombre[j]) {
				subcadena+=nombre[j];
				j++;
			} else {
				if (subcadena == nombre) {
					encontrado = true;
					cout<<cadena<<endl;
					j = 0;
					subcadena = "";
					
				} else {
					j=0;
					subcadena="";
				}
			}
		}
	}
	if (!encontrado) cout<<"No encontrado"<<endl;
	a.close();
	
	return 0;
}