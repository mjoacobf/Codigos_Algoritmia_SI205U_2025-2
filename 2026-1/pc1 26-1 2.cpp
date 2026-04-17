/*
Escribir un programa en C++ que solicita al usuario un numero X de 6 cifras. El programa debe extraer los digitos
que ocupan las posiciones pares(segunda, cuarta, sexta) y formar con ellos un numero Y de 3 cifras.
Luego, debe calcular la suma de los digitos del numero original X que sean mayores a 5. Finalmente, indique si el
numero Y es multiplo de dicha suma.
Ejemplo 1: X=172839. Digitos en posiciones pares: 7, 8, 9. Formamos Y = 789. Digitos de X>5: 7, 8, 9 (Suma =
24). Resultado: 789 no es multiplo de 24.
Ejemplo 2: X=461250. Digitos en posiciones pares: 6, 2, 0. Formamos Y = 620. Digitos de X>5: 6 (Suma = 6).
Resultado: 620 no es multiplo de 6.

Nota: No se deben usar: arreglos, cadenas ni funciones.

Nota: resolver sin emplear arreglos, ni cadenas, ni funciones externas ni propias.
*/

#include<iostream>

using namespace std;

int main() {
	int x;
	int y = 0;
	int sum = 0;
	
	cout<<"X: ";cin>>x;
	
	int t = x;
	int conteo = 1;
	for (int i = 6; i>0; i--) {
		if (i%2==0) {
			int cifra = t%10;
			y+=conteo*cifra;
			conteo*=10;
		}
		t/=10;
	}
	
	t = x;
	while (t>0) {
		int cifra = t%10;
		if (cifra>5) sum+=cifra;
		t/=10;
	}
	
	cout<<"Numero Y: "<<y<<endl;
	cout<<"Suma: "<<sum<<endl;
	if (y%sum==0) {
		cout<<"Y es multiplo de la suma";
		return 0;
	}
	
	cout<<"Y no es multiplo de la suma";
	return 0;
}