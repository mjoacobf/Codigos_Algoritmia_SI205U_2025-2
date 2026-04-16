#include<iostream>
using namespace std;
int main() {
	int num = 0;
	int e;
	float sum = 0;
	int n = 0;
	int superiores = 0;
	do {
		cout<<"Ingrese el numero de edades a ingresar: ";cin>>n;	
	} while (n <= 0);
	
	for (int i = 0; i<n; i++) {
		e = 0;
		do {
			cout<<"Ingrese la edad del nino "<<i+1<<" (<10): ";cin>>e;
		} while (e <= 0 or e >= 10);
		num*=10;
		num+=e;
		sum += e;
	}
	
	float prom = sum/n;
	
	for (int i = 0; i<n; i++) {
		int c = num%10;
		if (c*1.0 > prom) superiores++;
		num/=10;
	}
	
	cout<<superiores<<" ninos superan el promedio ("<<prom<<")."<<endl;
}
