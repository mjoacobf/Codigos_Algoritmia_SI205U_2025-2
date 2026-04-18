#include<iostream>

using namespace std;

int main(){
	char x[100];
	
	cin.getline(x,100);
	
	int letras = 0;
	int dig = 0;
	int num = 0;
	
	int cant = 0;
	int i = 0;
	while (x[i]!='\0') {
		cant++;
		
		if (x[i] - '0' >= 0 and x[i] - '0'<=9) {
			dig++;
			num*=10;
			num+= x[i]-'0';
			
			int j = i;
				while (x[j] != '\0') {
					x[j] = x[j+1];
					j++;
				}
			i=0;
			
		} else {
			if (x[i] == x[i+1]) {
				letras++;
				
				int j = i;
				while (x[j] != '\0') {
					x[j] = x[j+1];
					j++;
				}
				i=0;
			}
		}
		
		
		
		i++;
	}
	
	i = 0;
	while (x[i]!='\0') {
		cout<<x[i];
		i++;
	}
	
	cout<<endl<<"Numero: "<<num<<endl<<"Se retiraron "<<letras<<" letras y "<<dig<<" numeros.";
	
	return 0;
}