#include<iostream>

using namespace std;

struct reg_nodo {
	int numero;
	reg_nodo *psigue;
} *pinicio, *pactual;

void push(int num) {
	if (pinicio == NULL) {
		pinicio = new reg_nodo;
		pinicio->numero = num;
		pinicio->psigue = NULL;
		cout<<"Se agrego "<<num<<" a la pila."<<endl;
	} else {
		pactual = new reg_nodo;
		pactual->numero = num;
		cout<<"Se agrego "<<num<<" a la pila."<<endl;
		pactual->psigue = pinicio;
		pinicio = pactual;
		pactual = NULL;
	}
}

void pop() {
	if (pinicio != NULL) {
		pactual = pinicio->psigue;
		cout<<"Se retiro "<<pinicio->numero<<" de la lista."<<endl;
		delete pinicio;
		pinicio = pactual;
		pactual = NULL;
	} else cout<<"La pila esta vacia."<<endl;
}

int main() {
	
	
	int n = 0;
	do {
		cout<<"n: ";cin>>n;
	} while (n<=0);
	
	int x[n];
	
	for (int i = 0; i<n; i++) {
		cout<<"x["<<i<<"]: ";cin>>x[i];
	}
	
	for (int i = 0; i<n; i++) {
		if (x[i]>0) {
			push(x[i]);
		} else if (x[i] == -1) {
			pop();
		} else if (x[i] == -2) {
			if (pinicio == NULL) cout<<"La pila esta vacia."<<endl;
			else {
			pactual = pinicio;
				while (pactual!=NULL) {
					cout<<pactual->numero<<endl;
					pactual=pactual->psigue;
				}
			}
		}
	}
	cout<<"Resultado:"<<endl;
	if (pinicio == NULL) cout<<"La pila esta vacia."<<endl;
	else {
		pactual = pinicio;
		while (pactual!=NULL) {
			cout<<pactual->numero<<endl;
			pactual=pactual->psigue;
		}
	}
	
	return 0;
}
/*
12
5
10
-1
7
-2
-1
-1
15
-2
0
-5
25
*/