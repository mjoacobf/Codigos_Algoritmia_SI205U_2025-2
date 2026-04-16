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

void preorden(arbol *praiz) {
	if (praiz!=NULL) {
		cout<<praiz->numero<<endl;
		preorden(praiz->pizq);
		preorden(praiz->pder);
	}
}

void posorden(arbol *praiz) {
	if (praiz!=NULL) {
		posorden(praiz->pizq);
		posorden(praiz->pder);
		cout<<praiz->numero<<endl;
	}
}

int main() {
	
	ifstream a("NUMEROS.TXT");
	int dato;
	while (a>>dato) {
		insertarnodo(praiz,dato);
	}
	a.close();
	/*int n;
	cout<<"n: ";cin>>n;
	for (int i = 1; i<=n; i++) {
		int dato;
		cout<<"Dato "<<i<<": ";cin>>dato;
		
		insertarnodo(praiz,dato);
	}*/
	cout<<"Preorden: "<<endl;
	preorden(praiz);
	cout<<endl<<"Posorden: "<<endl;
	posorden(praiz);
	cout<<endl<<"Datos ordenados de menor a mayor: "<<endl;
	mostrararbol(praiz);
	cout<<endl<<"Datos ordenados de mayor a menor: "<<endl;
	mostrararbol2(praiz);
	
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
