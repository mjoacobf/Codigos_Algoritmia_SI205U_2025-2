#include<iostream>

using namespace std;

struct arbol {
	char palabra[200];
	arbol *pizq;
	arbol *pder;
} *praiz, *pactual, *paux;

int longitud(char pal[]) {
	int i = 0;
	while (pal[i]!='\0') i++;
	return i;
}

arbol *crearnodo(char pal[]) {
	arbol *p;
	p = new arbol;
	
	int i = 0;
	while (pal[i]!='\0') {
		p->palabra[i]=pal[i];
		i++;
	}
	p->palabra[i]='\0';
	
	p->pizq=NULL;
	p->pder=NULL;
	
	return p;
}

void insertarnodo(arbol *&p, char pal[]) {
	if (p==NULL) {
		p = crearnodo(pal);
	} else {
		if (longitud(pal)<=longitud(p->palabra)) {
			insertarnodo(p->pizq, pal);
		} else {
			insertarnodo(p->pder,pal);
		}
	}
}

void mostrararbol(arbol *praiz) {
	if (praiz!=NULL) {
		mostrararbol(praiz->pizq);
		cout<<praiz->palabra<<endl;
		mostrararbol(praiz->pder);
	}
}

void mostrararbol2(arbol *praiz) {
	if (praiz!=NULL) {
		mostrararbol2(praiz->pder);
		cout<<praiz->palabra<<endl;
		mostrararbol2(praiz->pizq);
	}
}

int main() {
	/*int n;
	cout<<"n: ";cin>>n;
	cin.ignore();
	for (int i = 1; i<=n; i++) {
		
		char x[200];
		cout<<"Dato "<<i<<": ";cin.getline(x,200);
		
		insertarnodo(praiz,x);
	}*/
	
	char x[200];
	cin.getline(x,200);
	int i = 0;
	while (x[i]!='\0') {
		while (x[i]!='\0' and x[i]==' ') i++;
		int j = 0;
		char p[200];
		while (x[i]!='\0' and x[i]!=' ') {
			p[j] = x[i];
			j++;
			i++;
		}
		p[j] = '\0';
		
		insertarnodo(praiz,p);
	}
	
	// :D
	
	cout<<"Datos ordenados de menor a mayor: "<<endl;
	mostrararbol(praiz);
	cout<<endl<<"Ordenados de mayor a menor: "<<endl;
	mostrararbol2(praiz);
	
	return 0;
}
