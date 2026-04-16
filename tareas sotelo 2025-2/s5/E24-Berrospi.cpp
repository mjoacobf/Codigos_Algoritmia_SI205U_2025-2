#include<iostream>
#include<string>

using namespace std;

int main() {
	char oracion[100];
	int vocales = 0;
	
	cout<<"Ingrese una oracion: ";cin.getline(oracion, 100);
	for (int i = 0; oracion[i]!='\0'; i++) {
		if (oracion[i] == 'A' or oracion[i] == 'E' or oracion[i] == 'I' or oracion[i] == 'O' or oracion[i] == 'U' or oracion[i] == 'a' or oracion[i] == 'e' or oracion[i] == 'i' or oracion[i] == 'o' or oracion[i] == 'u') {
			vocales++;
		}
	}
	
	cout<<"La oracion contiene "<<vocales<<" vocales en total.";
	
	return 0;
}
