#include<iostream>

using namespace std;

int main() {
	int categoria;
	int horasTrabajadas;
	cout<<"Ingrese categoria (1-4): ";cin>>categoria;
	cout<<"Ingrese horas trabajadas: ";cin>>horasTrabajadas;
	
	int pago;
	switch(categoria) {
		case 1:
			pago = 200;
			break;
		case 2:
			pago = 280;
			break;
		case 3:
			pago = 400;
			break;
		case 4:
			pago = 500;
			break;
		default:
			cout<<"Categoria no valida";
			return 0;
	}
	
	if (horasTrabajadas <= 40) pago+=10*horasTrabajadas;
	else if (horasTrabajadas <= 55) {
		pago+=10*40;
		pago+=20*(horasTrabajadas-40);
	} else if (horasTrabajadas <= 60) {
		pago+=10*40;
		pago+=20*15;
		pago+=30*(horasTrabajadas-55);
	} else {
		pago+=10*40;
		pago+=20*15;
		pago+=30*5;
	}
	
	cout<<"Monto a pagar: "<<pago;
}