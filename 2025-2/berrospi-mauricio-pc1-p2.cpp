#include<iostream>
using namespace std;

int main() {
	int dia1;
	int dia2;
	int dia3;
	int dia4;
	int mes1;
	int mes2;
	int mes3;
	int mes4;
	int ano1;
	int ano2;
	int ano3;
	int ano4;
	
	cout<<"Ingrese el dia de la fecha 1: ";cin>>dia1;
	cout<<"Ingrese el mes de la fecha 1: ";cin>>mes1;
	cout<<"Ingrese el ano de la fecha 1: ";cin>>ano1;
	long long int f1 = ano1*10000 + (12-mes1)*100 + dia1;
	
	cout<<"Ingrese el dia de la fecha 2: ";cin>>dia2;
	cout<<"Ingrese el mes de la fecha 2: ";cin>>mes2;
	cout<<"Ingrese el ano de la fecha 2: ";cin>>ano2;
	long long int f2= ano2*10000 + (12-mes2)*100 + dia2;
	
	cout<<"Ingrese el dia de la fecha 3: ";cin>>dia3;
	cout<<"Ingrese el mes de la fecha 3: ";cin>>mes3;
	cout<<"Ingrese el ano de la fecha 3: ";cin>>ano3;
	long long int f3 = ano3*10000 + (12-mes3)*100 + dia3;
	
	cout<<"Ingrese el dia de la fecha 4: ";cin>>dia4;
	cout<<"Ingrese el mes de la fecha 4: ";cin>>mes4;
	cout<<"Ingrese el ano de la fecha 4: ";cin>>ano4;
	long long int f4 = ano4*10000 + (12-mes4)*100 + dia4;
	
	if (f1 < f3) {
		int ta = ano3;
		int tm = mes3;
		int td = dia3;
		ano3 = ano1;
		mes3 = mes1;
		dia3 = dia1;
		ano1 = ta;
		mes1 = tm;
		dia1 = td;
	}
	if (f2 < f4) {
		int ta = ano4;
		int tm = mes4;
		int td = dia4;
		ano4 = ano2;
		mes4 = mes2;
		dia4 = dia2;
		ano2 = ta;
		mes2 = tm;
		dia2 = td;
	}
	
	if (f2 < f3) {
		int ta = ano3;
		int tm = mes3;
		int td = dia3;
		ano3 = ano2;
		mes3 = mes2;
		dia3 = dia2;
		ano2 = ta;
		mes2 = tm;
		dia2 = td;
	}
	
	if (f1 < f2) {
		int ta = ano2;
		int tm = mes2;
		int td = dia2;
		ano2 = ano1;
		mes2 = mes1;
		dia2 = dia1;
		ano1 = ta;
		mes1 = tm;
		dia1 = td;
	}
	if (f3 < f4) {
		int ta = ano4;
		int tm = mes4;
		int td = dia4;
		ano4 = ano3;
		mes4 = mes3;
		dia4 = dia3;
		ano3 = ta;
		mes3 = tm;
		dia3 = td;
	}
	
	cout<<"Fechas ordenadas de acuerdo con el criterio: "<<endl;
	cout<<dia1<<" "<<mes1<<" "<<ano1<<endl;
	cout<<dia2<<" "<<mes2<<" "<<ano2<<endl;
	cout<<dia3<<" "<<mes3<<" "<<ano3<<endl;
	cout<<dia4<<" "<<mes4<<" "<<ano4<<endl;
	
	return 0;
}
