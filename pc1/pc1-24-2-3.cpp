#include<iostream>
using namespace std;

int main() {
	int notas;
	int digitos;
	
	cin>>notas>>digitos;
	
	int mayorNota = 0;
	int menorNota = 21;
	
	for (int i = 20; i>0; i--) {
		int tn = notas;
		int td = digitos;
		
		while (tn>0) {
			int nota = tn%10;
			if (td%10==2) {
				tn/=10;
				int numtemp = tn%10;
				nota+=10*numtemp;
			}
			
			if (nota == i) {
				if (nota>mayorNota) {
					mayorNota = nota;
				}
				if (nota<menorNota) {
					menorNota = nota;
				}
				
				cout<<nota<<endl;
			}
			td/=10;
			tn/=10;
		}
	}
	
	cout<<"Mayor nota: "<<mayorNota<<endl;
	cout<<"Menor nota: "<<menorNota<<endl;
	
	return 0;
}