#include<iostream>

using namespace std;

int main() {
	struct reg_nodo {
		char c;
		reg_nodo *psigue;
	} *pinicio, *pactual, *pante, *paux;
	pinicio = NULL;
	
	char x[200];
	cin.getline(x,200);
	int i = 0;
	bool correcto = true;
	while (x[i]!='\0') {
		if (x[i] == '(') {
			pactual = new reg_nodo;
			if (pinicio==NULL) {
				pinicio = pactual;
				pinicio->psigue=NULL;
			} else {
				pactual->psigue = pinicio;
				pinicio = pactual;
			}
			
			pactual = NULL;
		}
		
		if (x[i] == ')') {
			if (pinicio!=NULL) {
				pactual=pinicio->psigue;
				delete pinicio;
				pinicio = pactual;
				pactual = NULL;
			} else {
				correcto = false;
			}
		}
		i++;
	}
	
	if (pinicio!=NULL) correcto = false;
	
	//hola profe
	
	if (correcto) {
		cout<<"Correcto"<<endl;
	} else {
		cout<<"Incorrecto"<<endl;
	}
	
	return 0;
}
