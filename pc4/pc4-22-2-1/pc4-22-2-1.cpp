#include<iostream>
#include<fstream>

using namespace std;

struct reg_nodo {
	//int codigo;
	string curso;
	//float promedio;
	
	int aprobados = 0;
	int alumnos = 0;
	
	reg_nodo *psigue;
} *pinicio, *pactual;

int extraercodigo(char x[]) {
	int i = 0;
	int codigo = 0;
	while (x[i]!='\0' and x[i]-'0'>=0 and x[i]-'0'<=9) {
		codigo*=10;
		codigo+=x[i]-'0';
		i++;
	}
	
	return codigo;
}

string extraernombre(char x[]) {
	int i = 0;
	while (x[i]!='\0' and x[i]-'0'>=0 and x[i]-'0'<=9) i++;
	while (x[i]!='\0' and x[i]==' ') i++;
	
	string nombre = "";
	while (x[i]!='\0' and x[i]!=' ') {
		
		nombre+=x[i];
		i++;
	}
	
	return nombre;
}

float extraernota(char x[]) {
	int i = 0;
	while (x[i]!='\0' and x[i]-'0'>=0 and x[i]-'0'<=9) i++;
	while (x[i]!='\0' and x[i]==' ') i++;
	while (x[i]!='\0' and x[i]!=' ') i++;
	while (x[i]!='\0' and x[i]==' ') i++;
	
	float nota = 0;
	bool flag = false;
	float count = 1;
	
	while (x[i]!='\0') {
		if (x[i]=='.' or x[i]==',') {
			flag = true;
			i++;
			if (x[i]=='\0') break;
		}
		
		if (not flag) {
			nota*=10;
			nota+=x[i]-'0';
		} else {
			count*=0.1;
			nota+=(x[i]-'0')*count;
		}
		
		i++;
	}
	
	return nota;
}

void buscar(reg_nodo *&pinicio, reg_nodo *&pactual, string nombre) {
	if (pinicio==NULL) {
		pinicio = new reg_nodo;
		pinicio->curso = nombre;
		pinicio->alumnos = 0;
		pinicio->aprobados = 0;
		pinicio->psigue = NULL;
		pactual = pinicio;
		return;
	} else {
		pactual = pinicio;
		while (pactual!=NULL) {
			if (pactual->curso == nombre) return;
			if (pactual->psigue == NULL) {
				pactual->psigue = new reg_nodo;
				pactual=pactual->psigue;
				break;
			} else {
				pactual = pactual->psigue;
			}
		}
		
		pactual->curso = nombre;
		pactual->alumnos = 0;
		pactual->aprobados = 0;
		pactual->psigue = NULL;
		return;
	}
}

int main() {
	ifstream a("ALUMNOS.TXT");
	
	char x[200];
	pinicio = NULL;
	while (a.getline(x,200)) {
		/*if (pinicio == NULL) {
			pinicio = new reg_nodo;
			pactual = pinicio;
		} else {
			pactual->psigue = new reg_nodo;
			pactual = pactual->psigue;
		}
		
		pactual->codigo = extraercodigo(x);
		pactual->curso = extraernombre(x);
		pactual->promedio = extraernota(x);
		
		pactual->psigue = NULL;*/
		
		string nombre = extraernombre(x);
		buscar(pinicio,pactual,nombre);
		pactual->alumnos++;
		if (extraernota(x)>=10.0) {
			pactual->aprobados++;
		}
	}
	
	a.close();
	
	pactual = pinicio;
	while (pactual!=NULL) {
		//cout<<"Codigo: "<<pactual->codigo<<endl;
		cout<<"Curso: "<<pactual->curso<<endl;
		//cout<<"Promedio: "<<pactual->promedio<<endl;
		cout<<"Aprobados: "<<pactual->aprobados<<endl;
		cout<<"Desaprobados: "<<pactual->alumnos - pactual->aprobados<<endl;
		cout<<endl;
		
		pactual = pactual->psigue;
	}
}
