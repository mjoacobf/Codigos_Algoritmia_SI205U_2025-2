/*
Disene un programa en C++, que permita leer un numero entero positivo cuyo numero de cifras sea mayor a
3 pero no mayor a 8. Luego el programa debe modificar el menor numero de digitos para que sea capicua
con el mismo numero de cifras. Si hubiese mas de una alternativa, presente el numero mayor.
Ejemplo 1:
Se ingresa el numero: 4667
Alternativas del capicua: 4664 o 7667, el mayor es 7667
El numero capicua es: 7667

Ejemplo 2:
Se ingresa el numero: 17357
El numero capicua es: 77377

Nota: No se pueden emplear arreglos, ni cadenas, ni funciones predefinidas ni definidas por el usuario.
*/

#include<iostream>

using namespace std;

int main() {
	int x;
	cout<<"Ingrese x: ";cin>>x;
	
	int xInvertido = 0;
	int t = x;
	while (t>0) {
		xInvertido*=10;
		xInvertido+=t%10;
		t/=10;
	}
	
	t = x;
	int ti = xInvertido;
	
	int capicua = 0;
	
	while (t>0) {
		int cifra1 = t%10;
		int cifra2 = ti%10;
		
		int mayor = cifra1;
		if (cifra2 > mayor) mayor = cifra2;
		
		capicua*=10;
		capicua+=mayor;
		t/=10;
		ti/=10;
	}
	
	cout<<capicua;
	return 0;
}