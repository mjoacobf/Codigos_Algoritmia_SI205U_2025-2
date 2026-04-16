#include<iostream>

using namespace std;

struct reg_nodo {
	int numero;
	reg_nodo *psigue;
} *pinicio, *pactual, *paux, *pante;

int main() {
	int n = 0;
	do {
		cout<<"Ingrese la cantidad de elementos: ";cin>>n;
	} while (n<=0);
	
	pinicio = NULL;
	//Entrada
	for (int i = 0; i<n; i++) {
		int e;
		cout<<"Numero "<<i+1<<": ";cin>>e;
		if (pinicio == NULL) {
			pinicio = new reg_nodo;
			pactual = pinicio;
		} else {
			pactual->psigue = new reg_nodo;
			pactual = pactual->psigue;
		}
		
		pactual->numero = e;
		pactual->psigue = NULL;
	}
	
	cout<<"La lista que ingreso es: "<<endl;
	pactual = pinicio;
	while (pactual!=NULL) {
		cout<<pactual->numero<<" ";
		pactual = pactual->psigue;
	}
	cout<<endl;
	
	//Eliminacion
	pactual = pinicio;
	while (pactual!=NULL) {
		bool elim = false;
		pante = pactual;
		paux = pactual->psigue;
		
		while (paux!=NULL) {
			if (pactual->numero == paux->numero) {
				elim = true;
				pante->psigue = paux->psigue;
				delete paux;
				paux = pante->psigue;
				break;
			}
			
			pante = paux;
			paux=paux->psigue;
		}
		
		
		if (not elim) {
			pactual=pactual->psigue;
		} else {
			pactual = pinicio;
		}
	}
	
	//Nueva lista
	cout<<"Luego de borrar los duplicados, se tiene: "<<endl;
	pactual = pinicio;
	while (pactual!=NULL) {
		cout<<pactual->numero<<" ";
		pactual = pactual->psigue;
	}
	cout<<endl;
	return 0;
/*
7
4
1
2
4
3
1
5
*/
}