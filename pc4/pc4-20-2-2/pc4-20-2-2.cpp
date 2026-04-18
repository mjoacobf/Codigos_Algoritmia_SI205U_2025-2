//Observacion: Una linea para un alumno seria: 127 Berrospi Frias 18 19 20

#include<iostream>
#include<fstream>

using namespace std;

struct reg_nodo {
	int codigo;
	char apellidos[30];
	int pc1;
	int pc2;
	int pc3;
	reg_nodo *psigue;
} *pinicio, *pactual;

int extraercodigo(char x[]) {
	int i = 0;
	int codigo = 0;
	while (x[i]!='\0' and x[i]==' ') i++;
	while (x[i]!='\0' and x[i]-'0'>=0 and x[i]-'0'<=9) {
		codigo*=10;
		codigo+=x[i]-'0';
		i++;
	}
	
	return codigo;
}

void agregarapellidos(char x[], reg_nodo *&pactual) {
	int i = 0;
	int j = 0;
	while (x[i]!='\0' and x[i]==' ') i++;
	while (x[i]!='\0' and x[i]-'0'>=0 and x[i]-'0'<=9) i++;
	while (x[i]!='\0' and x[i]==' ') i++;
	while (x[i]!='\0' and (x[i]-'0'<0 or x[i]-'0'>9)) {
		pactual->apellidos[j]=x[i];
		i++;
		j++;
	}
	pactual->apellidos[j]='\0';
}

int pc1(char x[]) {
	int i = 0;
	while (x[i]!='\0' and x[i]==' ') i++;
	while (x[i]!='\0' and x[i]-'0'>=0 and x[i]-'0'<=9) i++;
	while (x[i]!='\0' and x[i]==' ') i++;
	while (x[i]!='\0' and (x[i]-'0'<0 or x[i]-'0'>9)) i++;
	int nota = 0;
	while (x[i]!='\0' and x[i]-'0'>=0 and x[i]-'0'<=9) {
		nota*=10;
		nota+=x[i]-'0';
		i++;
	}
	return nota;
}

int pc2(char x[]) {
	int i = 0;
	while (x[i]!='\0' and x[i]==' ') i++;
	while (x[i]!='\0' and x[i]-'0'>=0 and x[i]-'0'<=9) i++;
	while (x[i]!='\0' and x[i]==' ') i++;
	while (x[i]!='\0' and (x[i]-'0'<0 or x[i]-'0'>9)) i++;
	while (x[i]!='\0' and x[i]-'0'>=0 and x[i]-'0'<=9) i++;
	while (x[i]!='\0' and (x[i]-'0'<0 or x[i]-'0'>9)) i++;
	int nota = 0;
	while (x[i]!='\0' and x[i]-'0'>=0 and x[i]-'0'<=9) {
		nota*=10;
		nota+=x[i]-'0';
		i++;
	}
	return nota;
}

int pc3(char x[]) {
	int i = 0;
	while (x[i]!='\0' and x[i]==' ') i++;
	while (x[i]!='\0' and x[i]-'0'>=0 and x[i]-'0'<=9) i++;
	while (x[i]!='\0' and x[i]==' ') i++;
	while (x[i]!='\0' and (x[i]-'0'<0 or x[i]-'0'>9)) i++;
	while (x[i]!='\0' and x[i]-'0'>=0 and x[i]-'0'<=9) i++;
	while (x[i]!='\0' and (x[i]-'0'<0 or x[i]-'0'>9)) i++;
	while (x[i]!='\0' and x[i]-'0'>=0 and x[i]-'0'<=9) i++;
	while (x[i]!='\0' and (x[i]-'0'<0 or x[i]-'0'>9)) i++;
	int nota = 0;
	while (x[i]!='\0' and x[i]-'0'>=0 and x[i]-'0'<=9) {
		nota*=10;
		nota+=x[i]-'0';
		i++;
	}
	return nota;
}

int main() {
	ifstream a("lista.txt");
	char x[100];
	pinicio = NULL;
	while (a.getline(x,200)) {
		if (pinicio == NULL) {
			pinicio = new reg_nodo;
			pactual = pinicio;
		} else {
			pactual->psigue = new reg_nodo;
			pactual = pactual->psigue;
		}
		pactual->codigo = extraercodigo(x);
		agregarapellidos(x, pactual);
		pactual->pc1 = pc1(x);
		pactual->pc2 = pc2(x);
		pactual->pc3 = pc3(x);
		pactual->psigue = NULL;
	}
	a.close();
	
	cout<<"Alumnos desaprobados:"<<endl;
	pactual = pinicio;
	while (pactual!=NULL) {
		float promedio = (pactual->pc1 + pactual->pc2 + pactual->pc3)*1.0/3;
		
		if (promedio < 10) {
			cout<<pactual->codigo<<endl;
			cout<<pactual->apellidos<<endl;
			cout<<pactual->pc1<<" "<<pactual->pc2<<" "<<pactual->pc3<<" (promedio "<<promedio<<")"<<endl;
		}
		pactual = pactual->psigue;
	}
	cout<<endl;
	
	cout<<"Alumnos aprobados:"<<endl;
	pactual = pinicio;
	while (pactual!=NULL) {
		float promedio = (pactual->pc1 + pactual->pc2 + pactual->pc3)*1.0/3;
		
		if (promedio >= 10) {
			cout<<pactual->codigo<<endl;
			cout<<pactual->apellidos<<endl;
			cout<<pactual->pc1<<" "<<pactual->pc2<<" "<<pactual->pc3<<" (promedio "<<promedio<<")"<<endl;
		}
		pactual = pactual->psigue;
	}
	cout<<endl;
	
	return 0;
}