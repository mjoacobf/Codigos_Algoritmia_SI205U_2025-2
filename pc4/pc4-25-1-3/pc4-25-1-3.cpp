#include<iostream>
#include<fstream>

using namespace std;

struct producto {
	int codigo;
	char descripcion[35];
	int stock;
	float precio;
} prod, tProd;

struct reg_nodo {
	producto info;
	reg_nodo *psigue;
} *pinicio, *pactual, *paux;

int extraerCodigo(char x[]) {
	int i = 0;
	int codigo = 0;
	while (x[i]!='\0' and not (x[i]>='0' and x[i]<='9')) i++;
	while (x[i]!='\0' and x[i]>='0' and x[i]<='9') {
		int digito = x[i]-'0';
		codigo*=10;
		codigo+=digito;
		i++;
	}
	return codigo;
}

void extraerDescripcion(char x[], char destino[]) {
	int i = 0;
	while (x[i]!='\0' and not (x[i]>='0' and x[i]<='9')) i++;
	while (x[i]!='\0' and x[i]>='0' and x[i]<='9') i++;
	while (x[i]!='\0' and x[i]==' ') i++;
	int j = 0;
	while (x[i]!='\0' and x[i]!=' ') {
		destino[j]=x[i];
		i++;
		j++;
	}
	destino[j]='\0';
	return;
}

int extraerStock(char x[]) {
	int i = 0;
	while (x[i]!='\0' and not (x[i]>='0' and x[i]<='9')) i++;
	while (x[i]!='\0' and x[i]>='0' and x[i]<='9') i++;
	while (x[i]!='\0' and x[i]==' ') i++;
	while (x[i]!='\0' and x[i]!=' ') i++;
	while (x[i]!='\0' and not (x[i]>='0' and x[i]<='9')) i++;
	int numero = 0;
	while (x[i]!='\0' and x[i]>='0' and x[i]<='9') {
		int digito = x[i]-'0';
		numero*=10;
		numero+=digito;
		i++;
	}
	return numero;
}

float extraerPrecio(char x[]) {
	int i = 0;
	while (x[i]!='\0' and not (x[i]>='0' and x[i]<='9')) i++;
	while (x[i]!='\0' and x[i]>='0' and x[i]<='9') i++;
	while (x[i]!='\0' and x[i]==' ') i++;
	while (x[i]!='\0' and x[i]!=' ') i++;
	while (x[i]!='\0' and not (x[i]>='0' and x[i]<='9')) i++;
	while (x[i]!='\0' and x[i]>='0' and x[i]<='9') i++;
	while (x[i]!='\0' and not (x[i]>='0' and x[i]<='9')) i++;
	float numero = 0;
	while (x[i]!='\0' and x[i]>='0' and x[i]<='9') {
		int digito = x[i]-'0';
		numero*=10;
		numero+=digito;
		i++;
	}
	if (x[i]=='.' or x[i]==',') {
		i++;
		float exp = 1;
		while (x[i]!='\0' and x[i]>='0' and x[i]<='9') {
			float digito = (x[i]-'0')*1.0;
			exp*=0.1;
			digito*=exp;
			numero+=digito;
			i++;
		}
	}
	return numero;
}

int main() {
	ifstream a("INVENTARIO.TXT");
	
	//entrada
	char x[200];
	pinicio = NULL;
	while(a.getline(x,200)) {
		prod.codigo = extraerCodigo(x);
		extraerDescripcion(x,prod.descripcion);
		prod.precio = extraerPrecio(x);
		prod.stock = extraerStock(x);
		
		if (pinicio == NULL) {
			pinicio = new reg_nodo;
			pactual = pinicio;
		} else {
			pactual->psigue = new reg_nodo;
			pactual = pactual->psigue;
		}
		
		pactual->info = prod;
		pactual->psigue = NULL;
	}
	
	//ordenamiento
	pactual = pinicio;
	while (pactual!=NULL) {
		paux = pactual->psigue;
		bool cambio = false;
		while (paux!=NULL) {
			if (pactual->info.stock > paux->info.stock) {
				cambio = true;
				tProd = pactual->info;
				pactual->info = paux->info;
				paux->info = tProd;
			} else if (pactual->info.stock == paux->info.stock) {
				if (pactual->info.precio < paux->info.precio) {
					cambio = true;
					tProd = pactual->info;
					pactual->info = paux->info;
					paux->info = tProd;
				}
			}
			
			if (cambio) break;
			
			paux=paux->psigue;
		}
		if (cambio) {
			pactual = pinicio;
			paux = NULL;
		} else {
			paux = pactual;
			pactual=pactual->psigue;
		}
		
	}
	
	//eliminacion
	ofstream bin("SinStock.DAT", ios::in|ios::binary);
	

	while (pinicio!=NULL) {
		if (pinicio->info.stock!=0) break;
		
		prod = pinicio->info;
		bin.write(reinterpret_cast<char *>(&prod),sizeof(producto));
		
		pactual=pinicio;
		if (pinicio!=NULL) {
			pactual = pactual->psigue;
			delete pinicio;
			pinicio = pactual;
		}
	}
	
	bin.close();
	
	//salida
	pactual = pinicio;
	while (pactual!=NULL) {
		cout<<pactual->info.codigo<<"\t"<<pactual->info.descripcion<<"\t"<<pactual->info.stock<<"\t"<<pactual->info.precio<<endl;
		pactual = pactual->psigue;
	}
	return 0;
}