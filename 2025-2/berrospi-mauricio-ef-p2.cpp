#include<iostream>
#include<fstream>

using namespace std;

struct reg_nodo {
	string nombre;
	int visitas;
	reg_nodo *psigue;
} *pinicio, *pactual, *paux;

void agregar (reg_nodo *&pinicio, string nombre) {
	if (pinicio == NULL) {
		pinicio = new reg_nodo;
		pinicio->nombre = nombre;
		pinicio->visitas = 1;
		pinicio->psigue = NULL;
		pactual = pinicio;
		return;
	} else {
		pactual= pinicio;
		while (pactual!=NULL) {
			if (pactual->nombre == nombre) {
				pactual->visitas++;
				return;
			}
			
			if (pactual->psigue == NULL) break;
			else pactual = pactual->psigue;
		}
		
		pactual->psigue = new reg_nodo;
		pactual = pactual->psigue;
		pactual->nombre = nombre;
		pactual->visitas = 1;
		pactual->psigue = NULL;
		return;
	}
}

bool comparar (string a, string b, int i) {
	if (a[i]==b[i]) return comparar(a, b, i+1);
	if (a[i]>b[i]) return true;
	else return false;
}

int main() {
	ifstream a("PLAYAS.TXT");
	char x[200];
	while(a.getline(x,200)) {
		string playa = "";
		for (int i = 0; x[i]!='\0'; i++) {
			playa+=x[i];
		}
		
		agregar(pinicio, playa);
	}
	
	a.close();
	
	//ordenamiento
	pactual = pinicio;
	while (pactual!=NULL) {
		paux = pactual->psigue;
		bool cambio = false;
		while(paux!=NULL) {
			int i = 0;
			if (comparar(pactual->nombre, paux->nombre, i)) {
					cambio = true;
					string t = pactual->nombre;
					int tv = pactual->visitas;
					pactual->nombre = paux->nombre;
					pactual->visitas = paux->visitas;
					paux->nombre = t;
					paux->visitas = tv;
				}
				if (cambio) break;
				paux=paux->psigue;
			}
			
		
		
		if (cambio) pactual = pinicio;
		else pactual = pactual->psigue;
	
	}
	//impresion
	cout<<"Playa\t\tVisitantes"<<endl;
	pactual = pinicio;
	while (pactual!=NULL) {
		cout<<pactual->nombre<<"\t\t"<<pactual->visitas<<endl;
		pactual = pactual->psigue;
	}
	cout<<endl;
	//buscando la cantidad maxima de visitantes
	
	int max = 0;
	bool flag = false;
	pactual = pinicio;
	while (pactual!=NULL) {
		if (pactual->visitas > max) {
			max = pactual->visitas;
		} else if (pactual->visitas == max) flag = true;
		
		pactual = pactual->psigue;
	}
	
	
	if (flag) {
		cout<<"Destinos con la mayor cantidad de visitantes:"<<endl;
	} else cout<<"Destino con la mayor cantidad de visitantes:"<<endl;
	
	
	pactual = pinicio;
	while (pactual!=NULL) {
		if (pactual->visitas == max) {
			cout<<pactual->nombre<<endl;
		}
		pactual = pactual->psigue;
	}
	
	
	
	return 0;
}