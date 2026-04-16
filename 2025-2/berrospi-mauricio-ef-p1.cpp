#include<iostream>
#include<fstream>

using namespace std;

struct reg_nodo {
	char c;
	reg_nodo *psigue;
} *pinicio, *pactual, *pilaimpresion;

void push (reg_nodo *&pinicio, char c) {
	if (pinicio == NULL) {
		pinicio = new reg_nodo;
		pinicio->psigue = NULL;
		pinicio->c = c;
	} else {
		pactual = new reg_nodo;
		pactual->c = c;
		pactual->psigue = pinicio;
		pinicio = pactual;
		pactual = NULL;
	}
}

char pop(reg_nodo *&pinicio) {
	if (pinicio!=NULL) {
		char c = pinicio->c;
		pactual = pinicio->psigue;
		delete pinicio;
		pinicio = pactual;
		pactual = NULL;
		return c;
	}
}

int main() {
	ifstream a("INPUT.TXT");
	char x[200];

	while (a.getline(x,200)) {
		int i = 0;
		while (x[i]!='\0') {
			if (x[i]!=']') {
				push(pinicio, x[i]);
			} else {
				string s = "";
				int l = 0;
				while (pinicio->c!='[') {
					s+=pop(pinicio);
					l++;
				}
				pop(pinicio);
				char numchar = pop(pinicio);
				int mult = numchar - '0';
				for (int j = 0; j<mult; j++) { //para q se repita tantas veces se mencione detras del corchete
					for (int k = l-1; k>=0; k--) { //agregar la cadena a repetir
						char agreg = s[k];
						push(pinicio, agreg);
					}
				}
			}
			i++;
		}
		
		//ahora toca invertir la pila D:
		
		while (pinicio!=NULL) {
			char c = pop(pinicio);
			push(pilaimpresion, c);
		}
		
		//se imprime
		
		pactual = pilaimpresion;
		while (pactual!=NULL) {
			cout<<pactual->c;
			pactual = pactual->psigue;
		}
		cout<<endl;
		
		//eliminando la pila de impresion para leer el siguiente
		
		while (pilaimpresion!=NULL) pop(pilaimpresion);
		
	}
	
	a.close();
	
	return 0;
}