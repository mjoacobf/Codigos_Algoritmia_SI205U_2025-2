#include<iostream>

using namespace std;

bool bisiesto(int a) {
	if (a%4 == 0 and not (a%100 == 0 and a%400 != 0)) return true;
	else return false;
}

bool validar (int m, int d, bool bisiesto) {
	if (m == 1 or m == 3 or m == 5 or m==7 or m==8 or m==10 or m==12) {
		if (d>0 and d<=31) return true;
		else return false;
	} else {
		if (m == 2) {
			if (d > 0 and (d<=28 or (bisiesto and d<=29))) return true;
			else return false;
		} else {
			if (d>0 and d<=30) return true;
		}
	}
}

int main() {
	int dia = 0;
	int mes = 0;
	int anio;
	
	cout<<"Introduce el anio: "; cin>>anio;
	do {
		cout<<"Introduce el mes: ";cin>>mes;
	} while (mes <= 0 or mes > 12);
	
	do {
		cout<<"Introduce el dia: ";cin>>dia;
	} while (not validar(mes,dia,bisiesto(anio)));
	
	if (mes == 1 or mes == 3 or mes == 5 or mes == 7 or mes == 8 or mes == 10) {
		if (dia == 31) {
			dia = 1;
			mes++;
		} else dia++;
	} else if (mes == 12) {
		if (dia == 31) {
			mes = 1;
			dia = 1;
			anio++;
		} else dia++;
	} else if (mes == 4 or mes == 6 or mes == 9 or mes == 11) {
		if (dia == 30) {
			mes++;
			dia = 1;
		} else dia++;
	} else if (mes == 2) {
		if (bisiesto(anio)) {
			if (dia == 29) {
				dia = 1;
				mes++;
			} else dia++;
		} else {
			if (dia == 28) {
				dia = 1;
				mes++;
			} else dia++;
		}
	}
	
	cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
	
	return 0;
}
