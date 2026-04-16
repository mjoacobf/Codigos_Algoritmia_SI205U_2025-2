#include<iostream>
#include<fstream>

using namespace std;

struct reg_nodo {
	int numero;
	reg_nodo *pante;
	reg_nodo *psigue;
} *pinicio, *pfin, *pactual, *paux;

//eliminar los no primos

bool esprimo(int num) {
	if (num <= 1) return false;
	for (int i = 2; i<num; i++) {
		if (num%i == 0) return false;
	}
	return true;
}

int main() {
	ifstream a("NUMEROS.TXT");
	int val;
	pinicio = NULL;
	pfin = NULL;
	while (a>>val) {
		if (pinicio == NULL) {
			pinicio = new reg_nodo;
			pinicio->pante = NULL;
			pactual = pinicio;
			pfin = pinicio;
		} else {
			pactual->psigue = new reg_nodo;
			paux = pactual;
			pactual = pactual->psigue;
			pactual->pante = paux;
			pfin = pactual;
		}
		pactual->numero = val;
		
		pactual->psigue = NULL;
	}
	
	a.close();
	
	cout<<"Se tiene: "<<endl;
	pactual = pinicio;
	while (pactual!=NULL) {
		cout<<pactual->numero<<endl;
		
		pactual=pactual->psigue;
	}
	
	//eliminacion
	
	pactual = pinicio;
	
	while (pactual!=NULL) {
		bool activ = false;
		if (not esprimo(pactual->numero)) {
			activ = true;
			if (pactual->pante!= NULL) {
				
					pactual->pante->psigue = pactual->psigue;
				if (pactual->psigue != NULL) {
					pactual->psigue->pante = pactual->pante;
				}
				
				paux = pactual->pante;
				delete pactual;
				pactual = paux;
			} else {
				if (pinicio->psigue!= NULL) {
					pinicio->psigue->pante = NULL;
					pinicio = pinicio->psigue;
					delete pactual;
					pactual = pinicio;
					
					paux = pfin->pante;
					delete pfin;
					pfin = paux;
					pfin->psigue = NULL;
				} else {
					delete pinicio;
					pactual = NULL;
					break;
				}
			}
			
			/*paux = pactual;
			while (paux->psigue!=NULL) {
				
				paux->numero = paux->psigue->numero;
				paux=paux->psigue;
				
			}
			
			pfin->pante->psigue = NULL;
			paux = pfin->pante;
			delete pfin;
			pfin=paux;
			
			
			
		}*/
	}
		if (not activ) {
			pactual=pactual->psigue;			
		}

	}
	
	cout<<"Luego de eliminar los no primos: "<<endl;
	pactual = pinicio;
	while (pactual!=NULL) {
		cout<<pactual->numero<<endl;
		pactual=pactual->psigue;
	}
	
	return 0;
}
