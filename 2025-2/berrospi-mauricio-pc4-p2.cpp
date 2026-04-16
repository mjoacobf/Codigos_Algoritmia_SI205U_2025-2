#include<iostream>
#include<fstream>

/*
ENCUESTA.TXT

120 S 140 S 110 N
140 N 110 S
130 S 140 N 120 S
120 N 110 S
*/

using namespace std;

struct reg_nodo {
	int candidato;
	int favor;
	int contra;
	reg_nodo *psigue;
} *pinicio, *pactual, *paux, *pante;

void buscar(reg_nodo *&pinicio, reg_nodo *&pactual, int codigo) {
	if (pinicio == NULL) {
		pinicio = new reg_nodo;
		pinicio->candidato = codigo;
		pinicio->favor = 0;
		pinicio->contra = 0;
		pinicio->psigue = NULL;
		pactual = pinicio;
		return;
	} else {
		pactual = pinicio;
		while (pactual!=NULL) {
			if (pactual->candidato == codigo) return;
			
			if (pactual->psigue!=NULL) pactual = pactual->psigue;
			else break; //hace que al acabar el bucle, si no se encontro, el puntero se ubique en el ultimo valor
		}
		
		pactual->psigue = new reg_nodo;
		pactual = pactual->psigue;
		pactual->candidato = codigo;
		pactual->favor = 0;
		pactual->contra = 0;
		pactual->psigue = NULL;
		return;
	}
}

int extraercandidato(char x[], int &i) { //donde i inicia cuando empieza el codigo
	int cod = 0;
	while (x[i]!='\0' and x[i]-'0'>=0 and x[i]-'0'<=9) {
		cod*=10;
		cod+=x[i]-'0';
		i++; //deja a i despues del codigo
	}
	return cod;
}

bool apoyo(char x[], int &i) {
	while (x[i]!='\0' and x[i]==' ') i++;
	if (x[i] == 'S') {
		i++;
		return true;
	} else {
		i++;
		return false;
	}
}

int main() {
	ifstream a("ENCUESTA.TXT");
	char x[200];
	while (a.getline(x,200)) {
		int i = 0;
		while (x[i]!='\0') {
			while (x[i]!='\0' and (x[i]-'0'<0 or x[i]-'0'>9)) i++; //hasta q llegue a un codigo de candidato
			
			int cand = extraercandidato(x, i);
			
			buscar(pinicio, pactual, cand);
			
			if (apoyo(x, i)) {
				pactual->favor++;
			} else pactual->contra++;
			if(x[i]=='\0') break; //despues de q se salte el caracter hay una posibilidad de q este sea el ultimo, sino sigue con el sgte voto
			i++;
		}
	}
	a.close();
	
	//Resultado
	
	pactual = pinicio;
	while (pactual!=NULL) {
		cout<<"El candidato "<<pactual->candidato<<" tiene "<<pactual->favor<<" voto(s) a favor (S) y "<<pactual->contra<<" voto(s) en contra (N)"<<endl;
		pactual = pactual->psigue;
	}
	
	
	
	return 0;
}