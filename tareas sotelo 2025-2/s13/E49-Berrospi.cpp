#include<iostream>

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

void mostrararbol(arbol *praiz) {
	if (praiz!=NULL) {
		mostrararbol(praiz->pizq);
		cout<<praiz->numero<<endl;
		mostrararbol(praiz->pder);
	}
}

void mostrararbol2(arbol *praiz) {
	if (praiz!=NULL) {
		mostrararbol2(praiz->pder);
		cout<<praiz->numero<<endl;
		mostrararbol2(praiz->pizq);
	}
}

int main() {
	int n;
	cout<<"n: ";cin>>n;
	for (int i = 1; i<=n; i++) {
		int dato;
		cout<<"Dato "<<i<<": ";cin>>dato;
		
		insertarnodo(praiz,dato);
	}
	
	cout<<"Datos ordenados: "<<endl;
	mostrararbol(praiz);
	cout<<endl<<"probando 2: "<<endl;
	mostrararbol2(praiz);
	
	return 0;
	/*
7
10
12
4
22
15
18
9
	*/
}
