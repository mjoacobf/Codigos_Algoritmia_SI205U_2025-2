#include<iostream>
#include<fstream>

using namespace std;

struct reg_nodo {
	int count = 1;
	char let[4];
	reg_nodo *psigue;
} *pinicio, *pactual, *paux;

int main() {
	ifstream a("DATOS.TXT");
	
	char x[200];
	
	pinicio = NULL;
	while (a.getline(x,200)) {
		if (pinicio == NULL) {
			pinicio = new reg_nodo;
			pactual = pinicio;
		} else {
			pactual->psigue = new reg_nodo;
			pactual = pactual->psigue;
		}
		
		int i = 0;
		int j = 0;
		bool ini = true;
		
		while (x[i]!='\0') {
			while (x[i]!='\0' and x[i]==' ') {
				i++;
				ini = true;
			}
			
			if (ini and x[i]!='\0') {
				pactual->let[j] = x[i];
				j++;
				ini = false;
			}
			
			if (x[i]=='\0') break;
			i++;
		}
		pactual->let[j]='\0';
		
		
		pactual->psigue = NULL;
	}
	
	//Suma
	pactual = pinicio;
	while (pactual!=NULL) {
		paux = pactual->psigue;
		while (paux!=NULL) {
			bool igual = true;
			int i = 0;
			while (i<3) {
				if (pactual->let[i]!=paux->let[i]) {
					igual = false;
					break;
				}
				i++;
			}
			
			if (igual) {
				paux->count++;
			}
			
			paux = paux->psigue;
		}
		
		pactual = pactual->psigue;
	}
	
	//Salida
	
	pactual = pinicio;
	while (pactual!=NULL) {
		int i = 0;
		while (pactual->let[i]!='\0') {
			cout<<pactual->let[i];
			i++;
		}
		
		if (pactual->count < 10) {
			cout<<0;
		}
		cout<<pactual->count<<endl;
		
		pactual = pactual->psigue;
	}
	
}