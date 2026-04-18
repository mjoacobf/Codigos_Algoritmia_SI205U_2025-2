#include<iostream>
#include<fstream>

using namespace std;

struct reg_nodo {
	char seccion;
	int aprobados;
	int sumanotas;
	int alumnos;
	reg_nodo *psigue;
} *pinicio, *pactual, *pante;

int nota (char p[]) {
	int num;
	if (p[2]!='\0') {
		num = (p[1]-'0')*10 + (p[2]-'0');
	} else {
		num = p[1]-'0';
	}
	
	return num;
}

void buscar(reg_nodo *&pinicio, reg_nodo *&pactual, char seccion) {
	
	if (pinicio == NULL) {
		pinicio = new reg_nodo;
		pinicio->seccion = seccion;
		pinicio->aprobados = 0;
		pinicio->sumanotas = 0;
		pinicio->alumnos = 1;
		pinicio->psigue = NULL;
		pactual=pinicio;
		return;
	} else {
		
		pactual = pinicio;
		while (pactual!=NULL) {
			if (pactual->seccion == seccion) {
				
				pactual->alumnos++;
				return;
			}
			if (pactual->psigue != NULL) pactual=pactual->psigue;
			else {
				pactual->psigue = new reg_nodo;
				pactual=pactual->psigue;
				break;
			}
		}
		pactual->seccion = seccion;
		pactual->aprobados = 0;
		pactual->sumanotas = 0;
		pactual->alumnos = 1;
		pactual->psigue = NULL;
		return;
	}
	
}

int main() {
	ifstream a("NOTAS.TXT");
	
	char x[4];
	pinicio = NULL;
	pactual = pinicio;
	while (a.getline(x,4)) {
		buscar(pinicio, pactual, x[0]);
		pactual->sumanotas+=nota(x);
		if (nota(x)>=10) {
			pactual->aprobados++;
		}
	}
	a.close();
	
	//Calculos
	int mayorAprobados = 0;
	pactual = pinicio;
	while (pactual!=NULL) {
		cout<<"Seccion: "<<pactual->seccion<<endl;
		cout<<"Alumnos en total: "<<pactual->alumnos<<endl;
		cout<<"Aprobados: "<<pactual->aprobados<<endl;
		float prom = (pactual->sumanotas)*1.0/(pactual->alumnos);
		cout<<"Promedio: "<<prom<<endl;
		cout<<endl;
		
		if (pactual->aprobados > mayorAprobados) {
			mayorAprobados = pactual->aprobados;
		}
		
		pactual=pactual->psigue;
	}
	
	cout<<"Secciones con mayor cantidad de aprobados: "<<endl;
	
	pactual = pinicio;
	while (pactual!=NULL) {
		while (pactual!=NULL and pactual->aprobados != mayorAprobados) pactual=pactual->psigue;
		if (pactual==NULL) break;
		cout<<"Seccion "<<pactual->seccion<<endl;
		cout<<"Numero de aprobados: "<<pactual->aprobados<<endl;
		float prom = (pactual->sumanotas)*1.0/(pactual->alumnos);
		cout<<"Promedio: "<<prom<<endl;
		pactual=pactual->psigue;
	}
	
	
	
	
	
	return 0;
}