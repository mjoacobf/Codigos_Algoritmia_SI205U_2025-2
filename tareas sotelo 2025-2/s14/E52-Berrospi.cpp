#include<iostream>
#include<fstream>

using namespace std;

struct arbol {
	int numero;
	arbol *pizq;
	arbol *pder;
} *praiz, *pactual, *paux;

arbol *crearnodo(int n) {
	arbol *p;
	p = new arbol;
	p->numero = n;
	p->pizq=NULL;
	p->pder=NULL;
	
	return p;
}

void insertarnodo(arbol *&p, int dato) {
	if (p==NULL) {
		p = crearnodo(dato);
	} else {
		if (dato<=p->numero) {
			insertarnodo(p->pizq, dato);
		} else {
			insertarnodo(p->pder,dato);
		}
	}
}

void imprimir(arbol *praiz, string esp) {
	if (praiz!=NULL) {
		imprimir(praiz->pder, esp+"  ");
		cout<<esp<<praiz->numero<<endl;
		imprimir(praiz->pizq,esp+"  ");
	}
}

int main() {
	
	ifstream a("NUMEROS.TXT");
	int dato;
	while (a>>dato) {
		insertarnodo(praiz,dato);
	}
	a.close();
	
	imprimir(praiz,"");
	
	return 0;
	/*
20
12
4
9
15
18
22
	*/
}
