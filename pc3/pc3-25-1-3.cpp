//PC3 25-1 3
#include<iostream>
using namespace std;

int main() {
	char x[200];
	cin.getline(x,200);
	
	int i = 0;
	string resultado = "";
	
	while(x[i]!='\0') {
		while(x[i]!='\0' and x[i]==' ') i++;
		//Palabra
		string b = "";
		int cb = 0;
		while (x[i]!='\0' and ((x[i]>='A' and x[i]<='Z') or (x[i]>='a' and x[i]<='z') or (x[i]>='0' and x[i]<='9'))) {
			if ((x[i]>='A' and x[i]<='Z') or (x[i]>='a' and x[i]<='z')) {
				b+=x[i];
				cb++;
			}
			i++;
		}
		
		for (int j = cb-1; j>=0; j--) {
			resultado+=b[j];
		}
		
		resultado+=' ';
		i++;
	}
	
	cout<<resultado;
	//I4NU OL45OS  ARAP   SE3RODAN41AG
	
	return 0;
}