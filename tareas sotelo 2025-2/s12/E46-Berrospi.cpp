#include<iostream>
#include<fstream>

using namespace std;

bool esprimo(int num) {
	if (num <=1) return false;
	for (int i = 2; i<num; i++) {
		if (num%i == 0) return false;
	}
	return true;
}

int main() {
	struct reg_nodo {
		int numero;
		reg_nodo *psigue;
	} *pinicio, *pactual, *pante, *paux;
	pinicio = NULL;
	
	ifstream a("Datos.txt");
	int val;
	while (a>>val) {
		if (pinicio==NULL) {
			pinicio = new reg_nodo;
			pactual=pinicio;
		} else {
			pactual->psigue=new reg_nodo;
			pactual=pactual->psigue;
		}
		
		
		pactual->numero = val;
		pactual->psigue=NULL;
	}
	
	//Recorrido
	cout<<"Lista inicial: "<<endl;
	pactual = pinicio;
	while (pactual!=NULL) {
		cout<<pactual->numero<<endl;
		pactual=pactual->psigue;
	}
	
	//Eliminacion
	pactual = pinicio;
	pante = NULL;
	while (pactual!=NULL) {
		bool activ = false;
		if (esprimo(pactual->numero)) {
			activ = true;
			if (pante != NULL) {
				pante->psigue=pactual->psigue;
				delete pactual;
			} else {
				pactual=pactual->psigue;
				delete pinicio;
				pinicio=pactual;
				pante = pinicio;
			}
			
			
			pactual=pante->psigue;
			
		}
		if (not activ) {
			pante = pactual;
			pactual=pactual->psigue;
		}
		
	}
	
	cout<<"Nueva lista: "<<endl;
	pactual = pinicio;
	while (pactual!=NULL) {
		cout<<pactual->numero<<endl;
		pactual=pactual->psigue;
	}
}
