#include<iostream>

using namespace std;

struct reg_nodo {
	int numero;
	reg_nodo *psigue;
} *pinicio, *pactual, *pante, *paux;

int main() {
	int n = 0;
	cout<<"n: ";cin>>n;
	int x[n];
	pinicio = NULL;
	for (int i = 0; i<n; i++) {
		cin>>x[i];
		
		if (pinicio == NULL) {
			pinicio = new reg_nodo;
			pactual = pinicio;
		} else {
			pactual->psigue = new reg_nodo;
			pactual = pactual->psigue;
		}
		
		pactual->numero = x[i];
		pactual->psigue = NULL;
	}
	
	pactual = pinicio;
	while (pactual!=NULL) {
		pante = NULL;
		paux = pactual->psigue;
		bool cambio = false;
		while (paux!=NULL) {
			if (pactual->numero == paux->numero) {
				cambio = true;
				if (pante == NULL) {
					pactual->psigue = paux->psigue;
					delete paux;
				} else {
					pante->psigue = paux->psigue;
					delete paux;
				}
			}
			
			if (not cambio) {
				pante = paux;
				paux = paux->psigue;
			} else break;
			
		}
		if (cambio) {
			pactual = pinicio;
		} else pactual = pactual->psigue;
	}
	
	cout<<"Lectura: "<<endl;
	pactual = pinicio;
	while (pactual!=NULL) {
		cout<<pactual->numero<<endl;
		pactual = pactual->psigue;
	}
	
	return 0;
}
