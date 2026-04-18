#include<iostream>
#include<fstream>

using namespace std;

struct reg_nodo {
	int numero;
	reg_nodo *psigue;
} *pinicio, *pactual, *paux, *plim;

void cambio(reg_nodo *&porigen, reg_nodo *&pactual, reg_nodo *plim) {
	pactual = porigen;
	while (pactual->psigue!=plim) pactual = pactual->psigue;
	if (pactual == porigen) return;
		int t = pactual->numero;
		pactual->numero = porigen->numero;
		porigen->numero = t;
		
		cambio(porigen->psigue, pactual, pactual);
}

int main() {
	ifstream a("DATOS.TXT");
	
	int val;
	pinicio = NULL;
	while(a>>val) {
		if (pinicio == NULL) {
			pinicio = new reg_nodo;
			pactual = pinicio;
		} else {
			pactual->psigue = new reg_nodo;
			pactual = pactual->psigue;
		}
		
		pactual->numero = val;
		pactual->psigue = NULL;
	}
	
	cout<<"Antes de intercambiar: "<<endl;
	pactual = pinicio;
	while (pactual!=NULL) {
		cout<<pactual->numero;
		cout<<endl;
		pactual=pactual->psigue;
	}
	
	cout<<endl;
	cambio(pinicio, pactual, NULL);
	cout<<"Despues de intercambiar: "<<endl;
	pactual = pinicio;
	while (pactual!=NULL) {
		cout<<pactual->numero;
		cout<<endl;
		pactual=pactual->psigue;
	}
}
