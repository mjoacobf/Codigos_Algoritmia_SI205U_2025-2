#include<iostream>
#include<fstream>

using namespace std;

int main() {
	char t = 's';
	while (t == 's' or t == 'S') {
		ifstream fichero("Agenda.txt");
		bool encontrado = false;
		int lc, ln, i, j;
		string nombre, cadena, subcadena;
		
		cout<<"Ingresar nombre a buscar en la agenda: ";
		getchar();
		getline(cin,nombre);
		
		ln = nombre.length();
		
		for (i = 0; i<ln; i++) {
			nombre[i] = toupper(nombre[i]);
		}
		
		while (!fichero.eof()) {
			getline(fichero,cadena);
			lc=cadena.length();
			for (i = 0; i<lc; i++) {
				cadena[i] = toupper(cadena[i]);
			}
			i = 0;
			j = 0;
			subcadena = "";
			while (i<lc) {
				if (cadena[i]==nombre[j]) {
					subcadena+=cadena[i];
					j++;
				} else {
					if (subcadena==nombre) {
						encontrado = true;
						j = 0;
						i = lc;
						subcadena = "";
						cout<<cadena<<endl;
					} else {
						j = 0;
						subcadena = "";
					}
				}
				i++;
			}
			fichero.close();
}
if (not encontrado) {
		
		cout<<"No encontrado. Desea probar de nuevo? (colocar S para intentar de nuevo): "<<endl;
		cin>>t;
		
	} else return 0;
}
return 0;
}
