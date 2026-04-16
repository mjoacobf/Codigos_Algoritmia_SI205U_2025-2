#include<iostream>
#include<fstream>

using namespace std;

struct vuelo {
	int codigo_vuelo;
	char destino[25];
	int asientos_totales;
	int asientos_disponibles;
	float precio_base;
	float ocupacion;
} rvuelo, tvuelo, auxvuelo;

struct reg_nodo {
	vuelo reg;
	reg_nodo *psigue;
} *pinicio, *pactual, *paux;

int extraercodigo(char x[]) {
	int i = 0;
	while (x[i]!='\0' and x[i] == ' ') i++;
	
	int cod = 0;
	while (x[i]!='\0' and x[i]-'0'>=0 and x[i]-'0'<=9) {
		cod*=10;
		cod+=x[i]-'0';
		i++;
	}
	return cod;
}

void extraerdestino(char x[], vuelo &rvuelo) {
	int i = 0;
	while (x[i]!='\0' and x[i] == ' ') i++;
	while (x[i]!='\0' and x[i]-'0'>=0 and x[i]-'0'<=9) i++; //codigo
	while (x[i]!='\0' and x[i]==' ') i++;
	
	int j = 0;
	while (x[i]!='\0' and x[i]!=' ') {
		rvuelo.destino[j] = x[i];
		i++;
		j++;
	}
	rvuelo.destino[j] = '\0';
}

int extraerasientostotales(char x[]) {
	int i = 0;
	while (x[i]!='\0' and x[i] == ' ') i++;
	while (x[i]!='\0' and x[i]-'0'>=0 and x[i]-'0'<=9) i++; //codigo
	while (x[i]!='\0' and x[i]==' ') i++;
	while (x[i]!='\0' and x[i]!=' ') i++; //destino
	while (x[i]!='\0' and x[i]==' ') i++;
	
	int as = 0;
	while (x[i]!='\0' and x[i]-'0'>=0 and x[i]-'0'<=9) {
		as*=10;
		as+=x[i]-'0';
		i++;
	}
	return as;
}

int extraerasientosdisponibles(char x[]) {
	int i = 0;
	while (x[i]!='\0' and x[i] == ' ') i++;
	while (x[i]!='\0' and x[i]-'0'>=0 and x[i]-'0'<=9) i++; //codigo
	while (x[i]!='\0' and x[i]==' ') i++;
	while (x[i]!='\0' and x[i]!=' ') i++; //destino
	while (x[i]!='\0' and x[i]==' ') i++;
	while (x[i]!='\0' and x[i]-'0'>=0 and x[i]-'0'<=9) i++; //asientos totales
	while (x[i]!='\0' and x[i]==' ') i++;
	
	int asd = 0;
	while (x[i]!='\0' and x[i]-'0'>=0 and x[i]-'0'<=9) {
		asd*=10;
		asd+=x[i]-'0';
		i++;
	}
	
	return asd;
}

float extraerpreciobase(char x[]) {
	int i = 0;
	
	while (x[i]!='\0' and x[i] == ' ') i++;
	while (x[i]!='\0' and x[i]-'0'>=0 and x[i]-'0'<=9) i++; //codigo
	while (x[i]!='\0' and x[i]==' ') i++;
	while (x[i]!='\0' and x[i]!=' ') i++; //destino
	while (x[i]!='\0' and x[i]==' ') i++;
	while (x[i]!='\0' and x[i]-'0'>=0 and x[i]-'0'<=9) i++; //asientos totales
	while (x[i]!='\0' and x[i]==' ') i++;
	while (x[i]!='\0' and x[i]-'0'>=0 and x[i]-'0'<=9) i++; //asientos disponibles
	while (x[i]!='\0' and x[i]==' ') i++;
	
	bool decim = false;
	float prec = 0;
	float pot = 1;
	while (x[i]!='\0' and ((x[i]-'0'>=0 and x[i]-'0'<=9) or x[i]==',' or x[i]=='.')) {
		if (x[i]==',' or x[i]=='.') {
			decim = true;
			i++;
		}
		if (x[i]=='\0') break;
		if (not decim) {
			prec*=10;
			prec+=x[i]-'0';
		} else {
			pot*=0.1;
			prec+=(x[i]-'0')*pot;
		}
		i++;
	}
	
	return prec;
}

int main() {
	char opc;
	cout<<"Escriba s para leer el binario. De lo contrario, se leera el archivo de texto. ";cin>>opc;
	//LECTURA DEL BINARIO
	if (opc=='s' or opc=='S') {
		ifstream b("VuelosAltaDemanda.DAT", ios::in|ios::binary);
		while (b.read(reinterpret_cast<char *>(&rvuelo), sizeof(vuelo))) {
			cout<<rvuelo.codigo_vuelo<<"\t";
			int i = 0;
			while (rvuelo.destino[i]!='\0') {
				cout<<rvuelo.destino[i];
				i++;
			}
			cout<<"\t"<<rvuelo.asientos_totales<<"\t"<<rvuelo.asientos_disponibles<<"\t"<<rvuelo.precio_base<<"\t"<<rvuelo.ocupacion<<endl;
		}
		b.close();
		return 0;
	}
	
	//ESCRITURA
	ifstream a("VUELOS.TXT");
	char x[200];
	pinicio = NULL;
	while (a.getline(x,200)) {
		if (pinicio ==NULL) {
			pinicio = new reg_nodo;
			pactual = pinicio;
		} else {
			pactual->psigue = new reg_nodo;
			pactual= pactual->psigue;
		}
		
		rvuelo.codigo_vuelo = extraercodigo(x);
		extraerdestino(x, rvuelo);
		rvuelo.asientos_totales = extraerasientostotales(x);
		rvuelo.asientos_disponibles = extraerasientosdisponibles(x);
		rvuelo.precio_base = extraerpreciobase(x);
		rvuelo.ocupacion = (rvuelo.asientos_totales - rvuelo.asientos_disponibles)*100.0/rvuelo.asientos_totales;
		
		pactual->reg = rvuelo;
		pactual->psigue = NULL;
	}
	
	a.close();
	
	//Vuelos alta demanda
	ofstream bin("VuelosAltaDemanda.DAT", ios::out|ios::binary);
	pactual = pinicio;
	while (pactual!=NULL) {
		rvuelo = pactual->reg;
		if (rvuelo.ocupacion>=90.0) {
			bin.write(reinterpret_cast<char *>(&rvuelo), sizeof(vuelo));
		}
		
		pactual = pactual->psigue;
	}
	bin.close();
	
	//Ordenamiento
	pactual = pinicio;
	while (pactual!=NULL) {
		int cambio = false;
		paux = pactual->psigue;
		rvuelo = pactual->reg;
		
		while (paux!=NULL) {
			tvuelo = paux->reg;
			if (rvuelo.ocupacion<tvuelo.ocupacion) {
				cambio = true;
				pactual->reg = tvuelo;
				paux->reg = rvuelo;
				break;
			}
			
			paux=paux->psigue;
		}
		
		if (not cambio) {
			pactual = pactual->psigue;
		} else pactual = pinicio;
		
	}
	
	cout<<"De forma ordenada, se tiene: "<<endl;
	pactual = pinicio;
	while (pactual!=NULL) {
		rvuelo = pactual->reg;
		
		cout<<rvuelo.codigo_vuelo<<"\t";
		int i = 0;
		while (rvuelo.destino[i]!='\0') {
			cout<<rvuelo.destino[i];
			i++;
		}
		cout<<"\t"<<rvuelo.asientos_totales<<"\t"<<rvuelo.asientos_disponibles<<"\t"<<rvuelo.precio_base<<"\t"<<rvuelo.ocupacion<<endl;
		
		pactual = pactual->psigue;
	}
	
	return 0;
}