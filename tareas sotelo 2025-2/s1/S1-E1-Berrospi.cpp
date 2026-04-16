#include<iostream>

using namespace std;

int main() {
	float h, r, v;
	cout<<"Introduzca el radio del cilindro (en m): ";cin>>r;
	cout<<"Introduzca la altura del cilindro (en m): ";cin>>h;
	
	v = r*r*3.1416*h;
	
	cout<<"El volumen del cilindro es de "<<v<<" m3"<<endl;
	
	return 0;
	
}
