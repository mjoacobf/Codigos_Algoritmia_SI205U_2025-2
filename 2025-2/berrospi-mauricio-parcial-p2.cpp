#include<iostream>

using namespace std;

int main() {
	char x[256];
	
	cin.getline(x,256);
	
	string oracion = "";
	
	int cantmayusincorr = 0;
	int cantnumeros = 0;
	
	int i = 0;
	while (x[i] != '\0') {
		while (x[i]!='\0' and (x[i]==' ')) i++;
		int corregido = 0;
		int len = 0;
		while (x[i] != '\0' and x[i] != ' ') {
			if (not (x[i] == '!' or x[i] == '¡' or x[i]==',' or x[i] =='.' or x[i] == '-' or x[i] == '(' or x[i] == ')' or x[i] == ':') and (x[i] - 0 >= 0 and x[i] - '0' <= 9)) {
				oracion+=x[i]; //agregar numeros
			}
		
			if (x[i] - '0' >= 0 and x[i] - '0' <= 9 and (x[i+1] == '-' or x[i+1] == '¡' or x[i+1] == '!' or x[i+1] == '.' or x[i+1] == ',' or x[i] == '(' or x[i] == ')' or x[i] == ':')) {
				if (x[i+2] != ' ') {
					oracion+=' '; //para evitar que se agregue un doble espacio
				}
				
				cantnumeros++; //eliminar simbolos entre numeros y caracteres + contar 1+ la cantidad de numeros si es un numero seguido de un simbolo
			}
			
			if (x[i] - '0' >= 0 and x[i] - '0' <= 9 and (x[i+1] == ' ' or x[i+1] == '\0')) cantnumeros++; //contar 1+ la cantidad de numeros sin eliminar un simbolo
			
			
			
			if ((x[i] - '0' < 0 or x[i] - '0' > 9) and x[i] != '!' and x[i] != '¡' and x[i] != ',' and x[i] != '.' and x[i] != '-' and x[i] != '(' and x[i] != ')' and x[i] != ':') { //no es numero ni simbolo no alfabetico
				if (len==0) oracion+=x[i];
				else {
					if (x[i] == 'A') {corregido = 1; oracion+='a';}
					else if (x[i] == 'B') {corregido = 1; oracion+='b';}
					else if (x[i] == 'C') {corregido = 1; oracion+='c';}
					else if (x[i] == 'D') {corregido = 1; oracion+='d';}
					else if (x[i] == 'E') {corregido = 1; oracion+='e';}
					else if (x[i] == 'F') {corregido = 1; oracion+='f';}
					else if (x[i] == 'G') {corregido = 1; oracion+='g';}
					else if (x[i] == 'H') {corregido = 1; oracion+='h';}
					else if (x[i] == 'I') {corregido = 1; oracion+='i';}
					else if (x[i] == 'J') {corregido = 1; oracion+='j';}
					else if (x[i] == 'K') {corregido = 1; oracion+='k';}
					else if (x[i] == 'L') {corregido = 1; oracion+='l';}
					else if (x[i] == 'M') {corregido = 1; oracion+='m';}
					else if (x[i] == 'N') {corregido = 1; oracion+='n';}
					else if (x[i] == 'O') {corregido = 1; oracion+='o';}
					else if (x[i] == 'P') {corregido = 1; oracion+='p';}
					else if (x[i] == 'Q') {corregido = 1; oracion+='q';}
					else if (x[i] == 'R') {corregido = 1; oracion+='r';}
					else if (x[i] == 'S') {corregido = 1; oracion+='s';}
					else if (x[i] == 'T') {corregido = 1; oracion+='t';}
					else if (x[i] == 'U') {corregido = 1; oracion+='u';}
					else if (x[i] == 'V') {corregido = 1; oracion+='v';}
					else if (x[i] == 'W') {corregido = 1; oracion+='w';}
					else if (x[i] == 'X') {corregido = 1; oracion+='x';}
					else if (x[i] == 'Y') {corregido = 1; oracion+='y';}
					else if (x[i] == 'Z') {corregido = 1; oracion+='z';}
					else oracion+=x[i];
				}
			}
			i++;
			len++;
		}
		
		
		if (corregido == 1) cantmayusincorr++;
		oracion+=' ';
	}
	

	cout<<"Texto corregido: "<<oracion<<endl;
	cout<<"Palabras con mayusculas corregidas: "<<cantmayusincorr<<endl;
	cout<<"Cantidad de numeros presentes: "<<cantnumeros<<endl;
	
	return 0;
}
