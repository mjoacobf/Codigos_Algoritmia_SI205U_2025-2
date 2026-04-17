/*
Disene un algoritmo que permita recibir dos numeros enteros positivos cuyo numero de cifras
sea menor a 9. Luego modificar el primer numero eliminando las cifras que existan en el
segundo numero.
Ejemplo 1: Si se ingresa 364798 y 427
El numero modificado sera 3698   (se elimino el 4 y el 7)

Ejemplo 2: Si se ingresa 3764972 y 1675
El numero modificado sera 3492    (se eliminaron el 6 y el 7)

Nota: resolver sin emplear arreglos, ni cadenas, ni funciones externas ni propias.
*/

#include<iostream>
using namespace std;

int main() {
	int numero1, numero2;
	
	cout<<"Primer numero: ";cin>>numero1;
	cout<<"Segundo numero: ";cin>>numero2;
	
	int copiaNumero1 = numero1;
	int nuevoNumero1 = 0;
	int conteo = 1;
	while (copiaNumero1 > 0) {
		int cifra1 = copiaNumero1%10;
		
		bool comun = false;
		int copiaNumero2 = numero2;
		while (copiaNumero2 > 0) {
			int cifra2 = copiaNumero2%10;
			if (cifra1 == cifra2) {
				comun = true;
				break;
			}
			copiaNumero2/=10;
		}
		
		if (not comun) {
			nuevoNumero1+=conteo*cifra1;
			conteo*=10;
		}
		
		copiaNumero1/=10;
	}
	
	cout<<nuevoNumero1;
	
	return 0;
}